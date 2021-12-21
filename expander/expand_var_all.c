/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 18:59:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static t_token	*update_head(t_token *current, t_token *head)
{
	if (current->prev == NULL)
		return (current->next);
	else
		return (head);
}

static t_token	*remove_empty_token(t_token *tokens)
{
	t_token	*head;
	t_token	*tmp;

	head = tokens;
	while (tokens != NULL)
	{
		if (tokens->word[0] == '\0')
		{
			tkn_lstlink(tokens->prev, tokens->next);
			head = update_head(tokens, head);
			tmp = tokens->next;
			tkn_lstdelone(tokens, free);
			tokens = tmp;
		}
		else
		{
			tokens = tokens->next;
		}
	}
	return (head);
}

t_token	*expand_var_all(t_token *tokens, t_dict *env)
{
	t_token	*head;
	char	*tmp;

	head = tokens;
	while (tokens != NULL)
	{
		if (search_prefix(tokens->word) != NULL)
		{
			tmp = tokens->word;
			tokens->word = expand_var(tokens->word, env);
			free(tmp);
		}
		tokens = tokens->next;
	}
	head = remove_empty_token(head);
	return (head);
}
