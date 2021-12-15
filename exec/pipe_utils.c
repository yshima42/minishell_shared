/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:01 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 12:18:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//change to stdfd
void	save_stdfd(t_info *info)
{
	info->stdfd[SAVED_IN] = xdup(STDIN_FILENO);
	info->stdfd[SAVED_OUT] = xdup(STDOUT_FILENO);
	info->stdfd[SAVED_ERR] = xdup(STDERR_FILENO);
}

void	close_stdfd(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	pipes_close(int pipes[][2], int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	redirect_reset(t_io *io_info, t_info *info)
{
	if (!is_redirect(io_info))
		return (0);
	xdup2(info->stdfd[SAVED_IN], STDIN_FILENO);
	xdup2(info->stdfd[SAVED_OUT], STDOUT_FILENO);
	xdup2(info->stdfd[SAVED_ERR], STDOUT_FILENO);
	return (0);
}

void	redirect_pipe(t_io *io_info, t_info *info)
{
	int	fd;

	if (!is_redirect(io_info))
		return ;
	while (io_info)
	{
		if (io_info->kind == OUT_REDIRECT)
		{
			fd = ft_open(io_info->word, OUT_REDIRECT);
			xdup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (io_info->kind == IN_REDIRECT)
		{
			fd = ft_open(io_info->word, IN_REDIRECT);
			xdup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (io_info->kind == APPEND)
		{
			fd = ft_open(io_info->word, APPEND);
			xdup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (io_info->kind == HEREDOC)
		{
			heredoc_handler(io_info, info);
		}
		io_info = io_info->next;
	}
}
