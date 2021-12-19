/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/19 11:26:22 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	launch_shell(t_proc *proc, t_info *info)
{
	bool	exit_flag;

	if (!proc)
		return (0);
	if (is_single_proc(proc))
		exit_flag = single_proc(proc, info);
	else
		exit_flag = multi_procs(proc, info);
	return (exit_flag);
}

int	loop_shell(t_info *info)
{
	char	*line;
	bool	exit_flag;
	int		parse_state;
	t_proc	*proc;

	exit_flag = 0;
	parse_state = DEFAULT;
	set_signal_in_read();
	while (!exit_flag)
	{
		printf("[%d]", g_exit_status);
		line = readline(GREEN"minishell"RESET" > ");
		if (line == NULL)
			break ;
		add_history(line);
		parse_state = parse_line(&proc, line, info->env);
		if (proc != NULL && is_redirect(proc->io_info))
			parse_state = heredoc_handler(proc);
		if (parse_state != DEFAULT)
		{
			free(line);
			continue ;
		}
		exit_flag = launch_shell(proc, info);
		free(line);
		proc_lstclear(&proc);
	}
	rl_clear_history();
	return (g_exit_status);
}
