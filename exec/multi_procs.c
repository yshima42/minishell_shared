/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:38:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 16:42:30 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	pids_wait(pid_t pids[], int num_pids)
{
	int	i;
	int	status;

	set_signal_ignore();
	i = 0;
	while (i < num_pids)
	{
		xwaitpid(pids[i], &status, 0);
		i++;
	}
	set_signal_in_read();
	if (WIFSIGNALED(status))
		return (display_sig_info(WTERMSIG(status)));
	else
		return (WEXITSTATUS(status));
}

static void	child_proc(t_proc *proc, int pipes[][2], t_info *info)
{
	g_exit_status = 0;
	if (!is_first_proc(proc))
	{
		xdup2(pipes[proc->id - 1][0], STDIN_FILENO);
		xclose(pipes[proc->id - 1][0]);
		xclose(pipes[proc->id - 1][1]);
	}
	if (!is_last_proc(proc))
	{
		xdup2(pipes[proc->id][1], STDOUT_FILENO);
		xclose(pipes[proc->id][0]);
		xclose(pipes[proc->id][1]);
	}
	if (!redirect(proc->io_info))
		exit(EXIT_FAILURE);
	if (is_builtin(proc->cmd))
	{
		if (!is_first_proc(proc))
			xclose(STDIN_FILENO);
		exec_builtin(proc, info);
		exit(g_exit_status);
	}
	ft_exec(proc->cmd, info);
}

int	multi_procs(t_proc *proc, t_info *info)
{
	int			pipes[MAX_PROC][2];
	pid_t		pids[MAX_PROC + 1];
	int			proc_num;
	extern int	g_exit_status;

	proc_num = proc_num_count(proc);
	set_signal_in_cmd();
	while (proc)
	{
		xpipe(pipes[proc->id]);
		pids[proc->id] = xfork();
		if (pids[proc->id] == 0)
			child_proc(proc, pipes, info);
		if (!is_first_proc(proc))
		{
			xclose(pipes[proc->id - 1][0]);
			xclose(pipes[proc->id - 1][1]);
		}
		proc = proc->next;
	}
	g_exit_status = pids_wait(pids, proc_num);
	return (0);
}
