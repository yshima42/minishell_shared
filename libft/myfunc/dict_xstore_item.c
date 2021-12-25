/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_xstore_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:33:23 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 19:13:57 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

// t_dict	*dict_xstore_item(char *line, char sep)
// {
// 	t_dict	*item;
// 	char	*key;
// 	char	*value;
// 	char	*sep_ptr;

// 	if (!line || !sep)
// 		return (NULL);
// 	sep_ptr = ft_strchr(line, sep);
// 	if (!sep_ptr)
// 		return (NULL);
// 	key = ft_xsubstr(line, 0, sep_ptr - line);
// 	value = ft_xstrdup(sep_ptr + 1);
// 	item = xdict_new(key, value);
// 	return (item);
// }

t_dict	*dict_xstore_item(char *line, char *connector)
{
	t_dict	*item;
	char	*key;
	char	*value;
	char	*cptr;

	if (!line || !connector)
		return (NULL);
	cptr = ft_strnstr(line, connector, ft_strlen(line));
	if (!cptr)
		return (NULL);
	key = dict_substr_key(line, connector);
	value = dict_substr_value(line, connector);
	item = xdict_new(key, value);
	return (item);
}
