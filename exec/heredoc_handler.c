/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 01:45:22 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//heredocmax message exit
static int	heredoc_open(char **heredoc_file_name)
{
	int		fd;
	char	*name;
	char	*i_str;
	int		i;

	name = ".heredoc";
	i = 0;
	fd = -1;
	while (fd == -1)
	{
		if (i == INT_MAX)
			xperror("too many .heredoc files");
		if (*heredoc_file_name)
			free(*heredoc_file_name);
		i_str = ft_xitoa(i);
		*heredoc_file_name = ft_strjoin(name, i_str);
		fd = open(*heredoc_file_name, O_WRONLY | O_EXCL | O_CREAT, 0666);
		free(i_str);
		i++;
	}
	return (fd);
}

//display plus nl
void	heredoc_handler(t_io *io_info, t_info *info)
{
	int		fd;
	char	*line;
	char	*heredoc_file_name;

	heredoc_file_name = NULL;
	redirect_reset(io_info, info);
	fd = heredoc_open(&heredoc_file_name);
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
	fd = ft_open(heredoc_file_name, IN_REDIRECT);
	xdup2(fd, STDIN_FILENO);
	unlink(heredoc_file_name);
	free(heredoc_file_name);
	close(fd);
}
