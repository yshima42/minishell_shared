/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:01 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 21:36:29 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	redirect_reset(t_io *io_info, t_info *info)
{
	if (!is_redirect(io_info))
		return (0);
	xdup2(info->stdfd[SAVED_IN], STDIN_FILENO);
	xdup2(info->stdfd[SAVED_OUT], STDOUT_FILENO);
	xdup2(info->stdfd[SAVED_ERR], STDOUT_FILENO);
	return (0);
}

static void	xdup2_xclose(int fd1, int fd2)
{
	xdup2(fd1, fd2);
	xclose(fd1);
}

void	redirect_pipe(t_io *io_info, t_info *info)
{
	int	fd;

	(void)info;
	if (!is_redirect(io_info))
		return ;
	while (io_info)
	{
		if (io_info->kind == OUT_REDIRECT)
		{
			fd = ft_xopen(io_info->word, OUT_REDIRECT);
			xdup2_xclose(fd, STDOUT_FILENO);
		}
		else if (io_info->kind == IN_REDIRECT)
		{
			fd = ft_xopen(io_info->word, IN_REDIRECT);
			xdup2_xclose(fd, STDIN_FILENO);
		}
		else if (io_info->kind == APPEND)
		{
			fd = ft_xopen(io_info->word, APPEND);
			xdup2_xclose(fd, STDOUT_FILENO);
		}
		else if (io_info->kind == HEREDOC)
		{
			fd = ft_xopen(io_info->heredoc_file, IN_REDIRECT);
			unlink(io_info->heredoc_file);
			free(io_info->heredoc_file);
			xdup2_xclose(fd, STDIN_FILENO);
		}	
		io_info = io_info->next;
	}
}
