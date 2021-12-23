/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 21:58:01 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static bool	launch_shell(t_proc *proc, t_info *info)
{
	bool	exit_flag;

	if (!proc)
		return (0);
	if (is_single_proc(proc))
		exit_flag = single_proc(proc, info);
	else
		exit_flag = multi_procs(proc, info);
	proc_lstclear(&proc);
	return (exit_flag);
}

void	loop_shell(t_info *info)
{
	char	*line;
	t_proc	*proc;

	set_signal_in_read();
	while (true)
	{
		printf("[%d]", g_exit_status);
		line = readline(GREEN"minishell"RESET" > ");
		if (line == NULL)
			break ;
		if (parse_line(&proc, line, info->env) != DEFAULT)
			continue ;
		if (launch_shell(proc, info) == EXIT)
			break ;
	}
}
