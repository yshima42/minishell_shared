/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:01 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 17:11:58 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	redirect_reset(t_io *io, t_info *info)
{
	if (!is_redirect(io))
		return (0);
	xdup2(info->stdfd[SAVED_IN], STDIN_FILENO);
	xdup2(info->stdfd[SAVED_OUT], STDOUT_FILENO);
	xdup2(info->stdfd[SAVED_ERR], STDOUT_FILENO);
	return (0);
}

static void	xdup2_xclose(int fd1, int fd2)
{
	if (fd1 == -1)
	{
		xclose(fd2);
		return ;
	}
	xdup2(fd1, fd2);
	xclose(fd1);
}

static int	redirect_heredoc(char *heredoc_file)
{
	int	fd;

	fd = ft_open(heredoc_file, IN_REDIRECT);
	xdup2_xclose(fd, STDIN_FILENO);
	unlink(heredoc_file);
	free(heredoc_file);
	return (fd);
}

static int	set_redirect(char *file, char *heredoc_file, enum e_kind open_mode)
{
	int	fd;

	if (open_mode == OUT_REDIRECT)
	{
		fd = ft_open(file, OUT_REDIRECT);
		xdup2_xclose(fd, STDOUT_FILENO);
	}
	else if (open_mode == IN_REDIRECT)
	{
		fd = ft_open(file, IN_REDIRECT);
		xdup2_xclose(fd, STDIN_FILENO);
	}
	else if (open_mode == APPEND)
	{
		fd = ft_open(file, APPEND);
		xdup2_xclose(fd, STDOUT_FILENO);
	}
	else
	{
		fd = redirect_heredoc(heredoc_file);
	}
	return (fd);
}

bool	redirect(t_io *io)
{
	if (!is_redirect(io))
		return (true);
	while (io)
	{
		if (io->is_empty)
		{
			ms_puterr_2arg(io->word, "ambiguous redirect");
			break ;
		}
		else
		{
			if (set_redirect(io->word, io->heredoc_file, io->kind) == -1)
				break ;
		}
		io = io->next;
	}
	if (io)
	{
		g_exit_status = 1;
		return (false);
	}
	else
	{
		return (true);
	}
}
