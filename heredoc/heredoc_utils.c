/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:14:27 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 01:20:37 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	heredoc_xopen(t_token *tokens)
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
		tokens->heredoc_file = ft_xstrjoin(directory, i_str);
		fd = open(tokens->heredoc_file, O_WRONLY | O_EXCL | O_CREAT, 0666);
		if (fd == -1)
			free(tokens->heredoc_file);
		free(i_str);
		i++;
	}
	return (fd);
}
