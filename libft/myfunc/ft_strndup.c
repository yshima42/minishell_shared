/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:46:23 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/10 16:50:01 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

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
	str = malloc(sizeof(char) * (ret_len + 1));
	ft_strlcpy(str, s1, ret_len + 1);
	return (str);
}
