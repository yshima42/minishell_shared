/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:51 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 15:15:07 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*search_prefix(char *word)
{
	enum e_quote	quote;

	quote = NONE;
	while (*word != '\0')
	{
		if (*word == '$' && quote != SINGLE && *(word + 1) != '\0')
			return (word);
		if (quote == NONE)
		{
			check_quote_begin(&quote, *word);
		}
		else
		{
			check_quote_end(&quote, *word);
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
