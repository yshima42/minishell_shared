/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:02:46 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 14:56:10 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static size_t	tkn_strlen_operator(const char *start)
{
	if (is_2chr_operator(start))
		return (2);
	else
		return (1);
}

bool	check_quote_begin(enum e_quote *quote, char c)
{
	if (c == '\'')
	{
		*quote = SINGLE;
		return (true);
	}
	if (c == '\"')
	{
		*quote = DOUBLE;
		return (true);
	}
	return (false);
}

bool	check_quote_end(enum e_quote *quote, char c)
{
	if (*quote == SINGLE && c == '\'')
	{
		*quote = NONE;
		return (true);
	}
	if (*quote == DOUBLE && c == '\"')
	{
		*quote = NONE;
		return (true);
	}
	return (false);
}

size_t	tkn_strlen_word(const char *start,  bool (*func)(char))
{
	size_t			len;
	enum e_quote	quote;

	len = 0;
	quote = NONE;
	while (*start != '\0')
	{
		if (quote == NONE)
		{
			check_quote_begin(&quote, *start);
			if (func(*start))
				break ;
		}
		else
		{
			check_quote_end(&quote, *start);
		}
		len++;
		start++;
	}
	return (len);
}

size_t	tkn_strlen(const char *start)
{
	if (is_operator(*start))
	{
		return (tkn_strlen_operator(start));
	}
	else
	{
		return (tkn_strlen_word(start, is_end));
	}
}
