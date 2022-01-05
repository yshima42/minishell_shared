/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_xsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:38:18 by yshimazu          #+#    #+#             */
/*   Updated: 2022/01/05 21:54:49 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*char_malloc(char const *src, char c)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	ptr = (char *)xmalloc(sizeof(char) * (len + 1));
	return (ptr);
}

static size_t	line_count(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	count++;
	return (count);
}

static void	add_current_dir(char **dest)
{
	char	**p;

	p = dest;
	while (*p)
	{
		if (**p == '\0')
		{
			free(*p);
			*p = ft_xstrdup(".");
		}
		p++;
	}
}

static void	set_each_string(size_t num, char **dest, const char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < num)
	{
		dest[i] = char_malloc(str, c);
		j = 0;
		while (*str != c && *str != '\0')
			dest[i][j++] = *str++;
		dest[i++][j] = '\0';
		if (*str == c)
			str++;
	}
	dest[i] = NULL;
}

char	**ms_xsplit(const char *str, char c)
{
	char	**dest;
	size_t	num;

	if (!str)
		return (NULL);
	num = line_count(str, c);
	dest = (char **)xmalloc(sizeof(char *) * (num + 1));
	if (str[0] == '\0')
	{
		dest[0] = NULL;
		return (dest);
	}
	set_each_string(num, dest, str, c);
	add_current_dir(dest);
	return (dest);
}
