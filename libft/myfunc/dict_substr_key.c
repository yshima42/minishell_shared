/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_substr_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:52:22 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 19:08:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_substr_key(char *line, char *connector)
{
	char	*key;
	char	*cptr;

	if (!line || !connector)
		return (NULL);
	cptr = ft_strnstr(line, connector, ft_strlen(line));
	if (!cptr)
		return (NULL);
	key = ft_xsubstr(line, 0, cptr - line);
	return (key);
}
