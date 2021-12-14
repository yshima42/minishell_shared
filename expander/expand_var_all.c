/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 15:12:16 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_token	*expand_var_all(t_token *tokens, t_info *info)
{
	t_token	*head;
	char	*tmp;

	head = tokens;
	while (tokens != NULL)
	{
		if (search_prefix(tokens->word) != NULL)
		{
			tmp = tokens->word;
			tokens->word = expand_var(tokens->word, info);
			free(tmp);
		}
		tokens = tokens->next;
	}
	return (head);
}
