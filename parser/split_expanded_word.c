/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expanded_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/23 15:58:10 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*split_token(t_token *old)
{
	t_token	*new;
	t_token	*new_head;
	char	*tmp_word;

	new_head = NULL;
	tmp_word = old->word;
	while (*tmp_word != '\0')
	{
		new = make_token(&tmp_word, SPLIT);
		if (new == NULL)
			break ;
		tkn_lstadd_back(&new_head, new);
	}
	return (new_head);
}

t_token	*split_expanded_word(t_token *old)
{
	t_token	*new_head;
	t_token	*old_head;
	t_token	*new;

	old_head = old;
	new_head = NULL;
	while (old != NULL)
	{
		if (old->kind == WORD && !old->is_empty)
			new = split_token(old);
		else
			new = tkn_lstdup(old);
		tkn_lstadd_back(&new_head, new);
		old = old->next;
	}
	tkn_lstclear(&old_head, free);
	return (new_head);
}
