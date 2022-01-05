/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:23 by yshimazu          #+#    #+#             */
/*   Updated: 2022/01/05 12:41:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static int	heredoc_xopen(t_token *tokens)
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

static int	heredoc_exit(t_token *tokens, t_token *head)
{
	g_exit_status = 1;
	unlink(tokens->heredoc_file);
	tkn_lstclear(&head, free);
	set_signal_in_read();
	return (HEREDOC_EXIT);
}

int	heredoc_handler(t_token *tokens, t_dict *env)
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
			if (store_heredoc(tokens, env, heredoc_fd) == HEREDOC_EXIT)
				return (heredoc_exit(tokens, head));
			tokens = tokens->next->next;
		}
	}
	set_signal_in_read();
	return (DEFAULT);
}
