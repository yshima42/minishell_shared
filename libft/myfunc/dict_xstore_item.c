/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_xstore_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:33:23 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 13:33:59 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*dict_xstore_item(char *line, char sep)
{
	t_dict	*item;
	char	*key;
	char	*value;
	char	*sep_ptr;

	if (!line || !sep)
		return (NULL);
	sep_ptr = ft_strchr(line, sep);
	if (!sep_ptr)
		return (NULL);
	key = ft_xsubstr(line, 0, sep_ptr - line);
	value = ft_xstrdup(sep_ptr + 1);
	item = xdict_new(key, value);
	return (item);
}
