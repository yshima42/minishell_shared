/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expanded_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:21:52 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static t_token	*split_one(t_token *old)
{
	t_token	*new;
	t_token	*new_head;
	char	*tmp_word;

	new_head = NULL;
	tmp_word = old->word;
	while (*tmp_word)
	{
		new = make_token(&tmp_word, SPLIT);
		if (!new)
			break ;
		tkn_lstadd_back(&new_head, new);
	}
	return (new_head);
}

t_token	*split_with_value_ifs(t_token *old)
{
	t_token	*new_head;
	t_token	*old_head;
	t_token	*new;

	old_head = old;
	new_head = NULL;
	while (old)
	{
		if (old->kind == WORD && !old->is_empty)
			new = split_one(old);
		else
			new = tkn_lstdup(old);
		tkn_lstadd_back(&new_head, new);
		old = old->next;
	}
	tkn_lstclear(&old_head, free);
	return (new_head);
}
