/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2022/01/05 01:34:53 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	heredoc_child(t_token *tokens, int heredoc_fd)
{
	char	*line;
	char	*delimiter;

	delimiter = tokens->next->word;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, heredoc_fd);
		free(line);
	}
	exit(0);
}

static int	heredoc_exit(t_token *tokens, t_token *head)
{
	g_exit_status = 1;
	unlink(tokens->heredoc_file);
	tkn_lstclear(&head, free);
	set_signal_in_read();
	return (HEREDOC_EXIT);
}

static void	heredoc_wait_close(pid_t pid, int *status, int heredoc_fd)
{
	set_signal_ignore();
	xwaitpid(pid, status, 0);
	xclose(heredoc_fd);
}

static int	store_heredoc(t_token *tokens, int heredoc_fd)
{
	pid_t	pid;
	int		status;

	pid = xfork();
	if (pid == 0)
	{
		heredoc_child(tokens, heredoc_fd);
	}
	else
	{
		heredoc_wait_close(pid, &status, heredoc_fd);
		if (WEXITSTATUS(status) == HEREDOC_EXIT)
			return (HEREDOC_EXIT);
	}
	return (DEFAULT);
}

int	heredoc_handler(t_token *tokens)
{
	int		heredoc_fd;
	t_token	*head;

	head = tokens;
	set_signal_in_heredoc();
	while (tokens)
	{
		if (tokens->kind != HEREDOC)
		{
			tokens = tokens->next;
		}
		else
		{
			heredoc_fd = heredoc_xopen(tokens);
			if (store_heredoc(tokens, heredoc_fd) == HEREDOC_EXIT)
				return (heredoc_exit(tokens, head));
			tokens = tokens->next->next;
		}
	}
	set_signal_in_read();
	return (DEFAULT);
}
