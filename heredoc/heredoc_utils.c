/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:14:27 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 17:59:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static int	heredoc_xopen(char **heredoc_file_name)
{
	int		fd;
	char	*directory;
	char	*i_str;
	int		i;

	directory = "/tmp/";
	i = 0;
	fd = -1;
	while (fd == -1)
	{
		if (i >= INT_MAX)
			xperror("too many heredoc files");
		i_str = ft_xitoa(i);
		*heredoc_file_name = ft_xstrjoin(directory, i_str);
		fd = open(*heredoc_file_name, O_WRONLY | O_EXCL | O_CREAT, 0666);
		if (fd == -1)
			free(*heredoc_file_name);
		free(i_str);
		i++;
	}
	return (fd);
}

void	heredoc_io_xopen(t_io *io_info)
{
	char	*heredoc_file_name;

	while (io_info)
	{	
		io_info->fd = heredoc_xopen(&heredoc_file_name);
		io_info->heredoc_file = heredoc_file_name;
		io_info = io_info->next;
	}
}
