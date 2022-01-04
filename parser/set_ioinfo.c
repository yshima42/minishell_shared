/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ioinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:07:12 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 01:15:35 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_redirect(t_token *tokens)
{
	size_t	io_num;

	io_num = 0;
	while (tokens && !is_pipe(tokens->kind))
	{
		if (is_io_operator(tokens->kind))
			io_num++;
		tokens = tokens->next;
	}
	return (io_num);
}

static t_io	*init_ioinfo(t_token *tokens)
{
	t_io	*head;
	t_io	*current;
	size_t	io_num;

	head = NULL;
	io_num = count_redirect(tokens);
	if (io_num == 0)
		return (NULL);
	while (io_num--)
	{
		current = io_lstnew();
		if (!current)
			exit(EXIT_FAILURE);
		io_lstadd_back(&head, current);
	}
	return (head);
}

t_io	*set_ioinfo(t_token *tokens)
{
	t_io	*io_info;
	t_io	*io_head;
	t_token	*current;

	if (!tokens)
		return (NULL);
	current = tokens;
	io_info = init_ioinfo(current);
	if (!io_info)
		return (NULL);
	io_head = io_info;
	while (current && !is_pipe(current->kind))
	{
		if (is_io_operator(current->kind))
		{
			io_info->kind = current->kind;
			io_info->word = ft_xstrdup(current->next->word);
			if (current->heredoc_file)
				io_info->heredoc_file = ft_xstrdup(current->heredoc_file);
			if (current->next->is_empty)
				io_info->is_empty = true;
			io_info = io_info->next;
		}
		current = current->next;
	}
	return (io_head);
}
