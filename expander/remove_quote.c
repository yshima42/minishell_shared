/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:08:07 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:24:05 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static size_t	count_quoting(char *word)
{
	size_t			count;
	enum e_quote	quote;

	count = 0;
	quote = NONE;
	while (*word)
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

static char	*strcpy_except_quoting(char *dest, char *src)
{
	char			*top;
	enum e_quote	quote;

	top = dest;
	quote = NONE;
	while (*src)
	{
		if (quote == NONE && check_quote_begin(&quote, *src) == true)
			;
		else if (quote != NONE && check_quote_end(&quote, *src) == true)
			;
		else
			*dest++ = *src;
		src++;
	}
	*dest = '\0';
	return (top);
}

static char	*remove_quoting_in_str(char *word)
{
	char			*new;
	size_t			count;
	size_t			len;

	count = count_quoting(word);
	if (count == 0)
		return (ft_xstrdup(word));
	len = ft_strlen(word) - count * 2 + 1;
	new = xmalloc(sizeof(char) * len);
	new = strcpy_except_quoting(new, word);
	return (new);
}

t_token	*remove_quoting(t_token *tokens)
{
	t_token	*head;
	char	*tmp;

	head = tokens;
	while (tokens)
	{
		if (tokens->kind == WORD)
		{
			tmp = tokens->word;
			tokens->word = remove_quoting_in_str(tokens->word);
			free(tmp);
		}
		tokens = tokens->next;
	}
	return (head);
}
