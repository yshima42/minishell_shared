/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 18:08:14 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	launch_shell(t_proc *proc, t_info *info)
{
	int	exit_flag;

	if (!proc)
		return (0);
	if (is_redirect(proc->io_info))
		heredoc_handler(proc);
	if (is_single_proc(proc))
		exit_flag = single_proc(proc, info);
	else
		exit_flag = multi_procs(proc, info);
	return (exit_flag);
}

//need change the free(froc)
//heredocを消す処理を入れる
//.heredocディレクトリを作って数字で管理
void	loop_shell(t_info *info)
{
	char	*line;
	bool	exit_flag;
	t_proc	*proc;

	exit_flag = 0;
	set_signal_in_read();
	while (!exit_flag)
	{
		printf("[%d]", g_exit_status);
		line = readline(GREEN"minishell"RESET" > ");
		if (line == NULL)
		{
			printf("Catch Ctrl-D\n");
			break ;
		}
		add_history(line);
		g_exit_status = parse_line(&proc, line, info->env);
		if (g_exit_status == EMPTY_LINE || g_exit_status == SYNTAX_ERR)
			continue ;
		exit_flag = launch_shell(proc, info);
		free(line);
		proc_lstclear(&proc);
	}
	rl_clear_history();
}
