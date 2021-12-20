/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/20 18:30:48 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//when(ft_strcmp == 0), needs free?
static void	heredoc_child(t_io *io_info)
{
	char	*line;

	while (io_info)
	{
		while (1)
		{
			line = readline("> ");
			if (line == NULL)
				break ;
			if (ft_strcmp(line, io_info->word) == 0)
			{
				free(line);
				break ;
			}
			ft_putendl_fd(line, io_info->fd);
			free(line);
		}
		io_info = io_info->next;
	}
	exit(0);
}

static void	heredoc_io_xclose(t_io *io_info)
{
	while (io_info)
	{	
		xclose(io_info->fd);
		io_info = io_info->next;
	}
}

static int	heredoc_exit(t_proc *proc)
{
	g_exit_status = 1;
	//unlinkで消す
	proc_lstclear(&proc);
	set_signal_in_read();
	return (HEREDOC_EXIT);
}

static void	heredoc_wait_close(pid_t pid, int *status, t_proc *proc)
{
	set_signal_ignore();
	xwaitpid(pid, status, 0);
	heredoc_io_xclose(proc->io_info);
}

int	heredoc_handler(t_proc *proc)
{
	pid_t	pid;
	int		status;

	set_signal_in_heredoc();
	while (proc)
	{
		if (!proc->io_info || proc->io_info->kind != HEREDOC)
		{
			proc = proc->next;
			continue ;
		}
		heredoc_io_xopen(proc->io_info);
		pid = xfork();
		if (pid == 0)
			heredoc_child(proc->io_info);
		else
		{
			heredoc_wait_close(pid, &status, proc);
			if (WEXITSTATUS(status) == HEREDOC_EXIT)
				return (heredoc_exit(proc));
			proc = proc->next;
		}
	}
	set_signal_in_read();
	return (DEFAULT);
}
