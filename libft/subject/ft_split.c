/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:47 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:16:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*skip_sep(char const *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}

static size_t	count_words(char const *str, char c)
{
	size_t	was_sep;
	size_t	num_words;

	num_words = 0;
	was_sep = 1;
	while (*str)
	{
		if (*str == c && was_sep == 0)
			was_sep = 1;
		if (*str != c && was_sep == 1)
		{
			num_words++;
			was_sep = 0;
		}
		str++;
	}
	return (num_words);
}

static size_t	count_char(char const *str, char c)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != c && str[idx])
		idx++;
	return (idx);
}

static void	*free_vector(char **splitted, size_t i)
{
	size_t	idx;

	idx = 0;
	while (idx < i)
	{
		free(splitted[idx]);
		idx++;
	}
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	num_words;
	size_t	len_word;
	size_t	idx;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!splitted)
		return (NULL);
	idx = 0;
	while (idx < num_words)
	{
		s = skip_sep(s, c);
		len_word = count_char(s, c);
		splitted[idx] = (char *)malloc(sizeof(char) * (len_word + 1));
		if (splitted[idx] == NULL)
			return (free_vector(splitted, idx));
		ft_strlcpy(splitted[idx], s, len_word + 1);
		s = s + len_word;
		idx++;
	}
	splitted[idx] = NULL;
	return (splitted);
}
