/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 20:02:12 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//heredocmax message exit
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

void	heredoc_child(t_io *io_info, int fd)
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
			ft_putendl_fd(line, fd);
			free(line);
		}
		io_info = io_info->next;
	}
	exit(0);
}

void	heredoc_handler(t_proc *proc)
{
	pid_t	pid;
	t_proc	*proc_p;
	int		fd;
	char	*heredoc_file_name;
	t_io	*io_p;

	proc_p = proc;
	while (proc_p)
	{
		if (!proc_p->io_info || proc_p->io_info->kind != HEREDOC)
		{
			proc_p = proc_p->next;
			continue ;
		}
		io_p = proc_p->io_info;
		while (io_p)
		{	
			fd = heredoc_xopen(&heredoc_file_name);
			io_p->heredoc_file = heredoc_file_name; 
			io_p = io_p->next;
		}
		pid = xfork();
		if (pid == 0)
			heredoc_child(proc_p->io_info, fd);
		waitpid(pid, NULL, 0);
		close(fd);
		proc_p = proc_p->next;
	}
}
