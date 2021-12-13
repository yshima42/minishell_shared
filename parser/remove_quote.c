/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:08:07 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/08 17:00:45 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	count_quote(char *word)
{
	size_t			count;
	enum e_quote	quote;

	count = 0;
	quote = NONE;
	while (*word != '\0')
	{
		if (quote == NONE)
		{
			check_quote_begin(&quote, *word);
		}
		else
		{
			if (check_quote_end(&quote, *word) == true)
				count++;
		}
		word++;
	}
	return (count);
}

char	*remove_quote_in_token(char *word)
{
	char			*new;
	char			*first;
	size_t			count;
	size_t			len;
	enum e_quote	quote;

	count = count_quote(word);
	if (count == 0)
		return (ft_xstrdup(word));
	len = ft_strlen(word) - count * 2 + 1;
	new = xmalloc(sizeof(char) * len);
	first = new;
	quote = NONE;
	while (*word != '\0')
	{
		if (quote == NONE && check_quote_begin(&quote, *word) == true)
			;
		else if (quote != WORD && check_quote_end(&quote, *word) == true)
			;
		else
			*new++ = *word;
		word++;
	}
	*new = '\0';
	return (first);
}

t_token	*remove_quote(t_token *tokens)
{
	t_token	*head;
	char	*tmp;

	head = tokens;
	while (tokens != NULL)
	{
		if (tokens->kind == WORD)
		{
			tmp = tokens->word;
			tokens->word = remove_quote_in_token(tokens->word);
			free(tmp);
		}
		tokens = tokens->next;
	}
	return (head);
}
