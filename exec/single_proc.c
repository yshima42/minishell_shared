/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:33:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 14:48:51 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	no_cmd_handler(t_proc *proc, t_info *info)
{
	redirect_pipe(proc->io_info, info);
	redirect_reset(proc->io_info, info);
	return (0);
}

//is_no_cmdをプロセスの中でやる
//need to think if you need to put is_no_cmd in fork or not
int	single_proc(t_proc *proc, t_info *info)
{
	pid_t	pid;
	int		exit_flag;
	int		status;

	exit_flag = 0;	
	if (is_builtin(proc->cmd))
	{
		redirect_pipe(proc->io_info, info);
		exit_flag = exec_builtin(proc, info);
		redirect_reset(proc->io_info, info);
		return (exit_flag);
	}
	set_signal_in_cmd();
	pid = xfork();
	if (pid == 0)
	{
		redirect_pipe(proc->io_info, info);
		ft_exec(proc->cmd, info);
	}
	set_signal_ignore();
	xwaitpid(pid, &status, 0);
	set_signal_in_read();
	if (WIFSIGNALED(status))
		g_exit_status = display_sig_info(WTERMSIG(status));
	else
		g_exit_status = WEXITSTATUS(status);
	return (exit_flag);
}
