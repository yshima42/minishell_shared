/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:05 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/09 16:44:48 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	child_proc(t_proc *proc, int pipes[][2], t_info *info)
{
	if (!is_first_proc(proc))
		xdup2(pipes[proc->id - 1][0], STDIN_FILENO);
	if (!is_last_proc(proc))
		xdup2(pipes[proc->id][1], STDOUT_FILENO);
	pipes_close(pipes, proc->id + 1);
	redirect_pipe(proc->io_info, info);
	if (is_builtin(proc->cmd))
	{
		if (!is_first_proc(proc))
			close(STDIN_FILENO);
		exec_builtin(proc, info);
		exit(0);
	}
	if (ft_exec(proc->cmd, info) == -1)
		xperror("child");
	return (0/* status */);
}

void	pids_wait(pid_t pids[], int num_pids)
{
	int	i;

	i = 0;
	while (i <= num_pids)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

//todo: num of fork return error
int	exec_multi_procs(t_proc *proc, t_info *info)
{
	int		pipes[MAX_PROC][2];
	pid_t	pids[MAX_PROC + 1];
	t_proc	*proc_p;

	proc_p = proc;
	while (proc_p)
	{
		xpipe(pipes[proc_p->id]);
		pids[proc_p->id] = xfork();
		if (pids[proc_p->id] == 0)
			child_proc(proc_p, pipes, info);
		if (!is_first_proc(proc_p))
		{
			close(pipes[proc_p->id - 1][0]);
			close(pipes[proc_p->id - 1][1]);
		}
		proc_p = proc_p->next;
	}
	pids_wait(pids, proc_num_count(proc));
	return (0);
}

int	exec_single_proc(t_proc *proc, t_info *info)
{
	pid_t	pid;
	pid_t	wpid;
	int		exit_flag;

	//これをforkの中に入れるかどうか検討
	exit_flag = 0;
	if (is_no_cmd(proc))
	{
		redirect_pipe(proc->io_info, info);
		redirect_reset(proc->io_info, info);
		return (exit_flag);
	}
	if (is_builtin(proc->cmd))
	{
		redirect_pipe(proc->io_info, info);
		exit_flag = exec_builtin(proc, info);
		redirect_reset(proc->io_info, info);
		return (exit_flag);
	}
	pid = xfork();
	if (pid == 0)
	{
		redirect_pipe(proc->io_info, info);
		if (ft_exec(proc->cmd, info) == -1)
			xperror("child");
	}
	wpid = waitpid(pid, NULL, 0);
	return (exit_flag); /* WEXITSTATUS(status) */
}

bool	launch_shell(t_proc *proc, t_info *info)
{
	int	exit_flag;

	if (!proc)
		return (0);
	if (is_single_proc(proc))
		exit_flag = exec_single_proc(proc, info);
	else
		exit_flag = exec_multi_procs(proc, info);
	return (exit_flag);
}
