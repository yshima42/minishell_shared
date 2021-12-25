/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_substr_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:08:21 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 19:10:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_substr_value(char *line, char *connector)
{
	char	*value;
	char	*cptr;

	if (!line || !connector)
		return (NULL);
	cptr = ft_strnstr(line, connector, ft_strlen(line));
	if (!cptr)
		return (NULL);
	value = ft_xstrdup(cptr + ft_strlen(connector));
	return (value);
}
