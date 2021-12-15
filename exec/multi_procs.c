/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:38:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 21:54:18 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	pids_wait(pid_t pids[], int num_pids)
{
	int	i;
	int	status;

	i = 0;
	while (i <= num_pids)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
	return (WEXITSTATUS(status));
}

/* check if you need to return status */
static int	child_proc(t_proc *proc, int pipes[][2], t_info *info)
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
	return (0);
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
	g_exit_status = pids_wait(pids, proc_num_count(proc));
	return (0);
}
