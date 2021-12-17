/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 10:20:58 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	heredoc_xopen(char **heredoc_file_name)
{
	int		fd;
	char	*directory;
	char	*i_str;
	int		i;

	directory = ".heredoc/";
	i = 0;
	fd = -1;
	while (fd == -1)
	{
		if (i >= INT_MAX)
			xperror("too many heredoc files");
		i_str = ft_xitoa(i);
		*heredoc_file_name = ft_xstrjoin(directory, i_str);
		fd = open(*heredoc_file_name, O_WRONLY | O_EXCL | O_CREAT, 0666);
		free(i_str);
		i++;
	}
	return (fd);
}

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
				break ;
			ft_putendl_fd(line, io_info->fd);
			free(line);
		}
		io_info = io_info->next;
	}
	exit(0);
}

static void	heredoc_io_xopen(t_io *io_info)
{
	char	*heredoc_file_name;

	while (io_info)
	{	
		io_info->fd = heredoc_xopen(&heredoc_file_name);
		io_info->heredoc_file = heredoc_file_name;
		io_info = io_info->next;
	}
}

static void	heredoc_io_xclose(t_io *io_info)
{
	while (io_info)
	{	
		xclose(io_info->fd);
		io_info = io_info->next;
	}
}

void	heredoc_handler(t_proc *proc)
{
	pid_t	pid;

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
		waitpid(pid, NULL, 0);
		heredoc_io_xclose(proc->io_info);
		proc = proc->next;
	}
}
