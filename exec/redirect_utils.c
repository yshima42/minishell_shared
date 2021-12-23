/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:01 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 01:01:51 by hyoshie          ###   ########.fr       */
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
	if (fd1 == -1)
	{
		xclose(fd2);
		return ;
	}
	xdup2(fd1, fd2);
	xclose(fd1);
}

static void	redirect_heredoc(t_io *io_info)
{
	int	fd;

	fd = ft_xopen(io_info->heredoc_file, IN_REDIRECT, CHILD);
	xdup2_xclose(fd, STDIN_FILENO);
	unlink(io_info->heredoc_file);
	free(io_info->heredoc_file);
}

static void	set_redirect(char *file, enum e_kind open_mode, bool is_child)
{
	int	fd;

	if (open_mode == OUT_REDIRECT)
	{
		fd = ft_xopen(file, OUT_REDIRECT, is_child);
		xdup2_xclose(fd, STDOUT_FILENO);
	}
	else if (open_mode == IN_REDIRECT)
	{
		fd = ft_xopen(file, IN_REDIRECT, is_child);
		xdup2_xclose(fd, STDIN_FILENO);
	}
	else if (open_mode == APPEND)
	{
		fd = ft_xopen(file, APPEND, is_child);
		xdup2_xclose(fd, STDOUT_FILENO);
	}
}

void	redirect_pipe(t_io *io_info, bool is_child)
{
	if (!is_redirect(io_info))
		return ;
	while (io_info)
	{
		if (io_info->is_empty)
		{
			ms_puterr_2arg(io_info->word, "ambiguous redirect");
			g_exit_status = 1;
			exit(EXIT_FAILURE);
		}
		else if (io_info->kind == HEREDOC)
			redirect_heredoc(io_info);
		else
			set_redirect(io_info->word, io_info->kind, is_child);
		io_info = io_info->next;
	}
}

// void	single_redirect_pipe(t_io *io_info)
// {
// 	if (!is_redirect(io_info))
// 		return ;
// 	while (io_info)
// 	{
// 		if (io_info->is_empty)
// 		{
// 			ms_puterr_2arg(io_info->word, "ambiguous redirect");
// 			g_exit_status = 1;
// 		}
// 		else if (io_info->kind == HEREDOC)
// 			redirect_heredoc(io_info);
// 		else
// 			set_redirect(io_info->word, io_info->kind, PARENT);
// 		io_info = io_info->next;
// 	}
// }
