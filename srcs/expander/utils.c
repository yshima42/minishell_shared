/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:51 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/26 19:32:44 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static bool	is_prefix_dollar(int current, int next, enum e_quote quote)
{
	if (current == '$' && quote != SINGLE)
	{
		if (is_shellvar_top(next) || next == '?')
			return (true);
	}
	return (false);
}

char	*search_prefix(char *word, enum e_quote *quote)
{
	while (*word != '\0')
	{
		if (is_prefix_dollar(*word, *(word + 1), *quote))
		{
			return (word);
		}
		if (*quote == NONE)
		{
			check_quote_begin(quote, *word);
		}
		else
		{
			check_quote_end(quote, *word);
		}
		word++;
	}
	return (NULL);
}

char	*ft_xstrjoin_free(char *str1, char *str2)
{
	char	*tmp;

	tmp = ft_xstrjoin(str1, str2);
	free(str1);
	return (tmp);
}

bool	is_shellvar_top(int c)
{
	if (ft_isalpha(c) || c == '_')
		return (true);
	else
		return (false);
}

bool	is_shellvar(int c)
{
	if (is_shellvar_top(c) || ft_isdigit(c))
		return (true);
	else
		return (false);
}
