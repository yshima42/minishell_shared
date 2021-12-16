/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 18:29:24 by yshimazu         ###   ########.fr       */
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
	/* char	*heredoc_file_name;
	int		fd;
	int		n; */
	
/* 	fd = heredoc_xopen(&heredoc_file_name);
	io_info->heredoc_file =heredoc_file_name; 
	n = ft_strlen(heredoc_file_nam) + 1;
	write(pipe[1], &n, sizeof(int));
	write(pipe[1], heredoc_file_name, sizeof(char) * n);
	close(pipe[1]); */
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
/* 	int		pipe[2]; */
	int		fd;
	char	*heredoc_file_name;
	t_io	*io_p;

	proc_p = proc;
	while (proc_p)
	{
		/* xpipe(pipe); */
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

//display plus nl
/* void	heredoc_handler(t_io *io_info, t_info *info)
{
	int		fd;
	char	*line;
	char	*heredoc_file_name;

	heredoc_file_name = NULL;
	redirect_reset(io_info, info);
	fd = heredoc_xopen(&heredoc_file_name);
	set_signal_in_heredoc();
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
	set_signal_in_cmd();
	close(fd);
	fd = ft_xopen(heredoc_file_name, IN_REDIRECT);
	xdup2(fd, STDIN_FILENO);
	unlink(heredoc_file_name);
	free(heredoc_file_name);
	close(fd);
} */
