/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 14:44:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_xstrdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	str = xmalloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	ret_len;
	size_t	src_len;

	if (s1 == NULL)
		return (NULL);
	src_len = ft_strlen(s1);
	if (src_len >= n)
		ret_len = n;
	else
		ret_len = src_len;
	str = xmalloc(sizeof(char) * (ret_len + 1));
	ft_strlcpy(str, s1, ret_len + 1);
	return (str);
}

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
