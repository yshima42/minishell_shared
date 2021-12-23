/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ioinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:07:12 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/23 16:18:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_redirect(t_token *tokens)
{
	size_t	io_num;

	io_num = 0;
	while (tokens != NULL && !is_pipe(tokens->kind))
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
	t_io	*tmp;
	size_t	io_num;

	head = NULL;
	io_num = count_redirect(tokens);
	if (io_num == 0)
		return (NULL);
	while (io_num--)
	{
		tmp = io_lstnew();
		if (tmp == NULL)
			exit(EXIT_FAILURE);
		io_lstadd_back(&head, tmp);
	}
	return (head);
}

t_io	*set_ioinfo(t_token *tokens)
{
	t_io	*io_info;
	t_io	*io_head;
	t_token	*tmp;

	if (tokens == NULL)
		return (NULL);
	tmp = tokens;
	io_info = init_ioinfo(tmp);
	if (io_info == NULL)
		return (NULL);
	io_head = io_info;
	while (tmp != NULL && !is_pipe(tmp->kind))
	{
		if (is_io_operator(tmp->kind))
		{
			io_info->kind = tmp->kind;
			io_info->word = ft_xstrdup(tmp->next->word);
			if (tmp->next->is_empty)
				io_info->is_empty = true;
			io_info = io_info->next;
		}
		tmp = tmp->next;
	}
	return (io_head);
}
