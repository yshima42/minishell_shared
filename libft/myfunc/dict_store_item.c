/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_store_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:32:35 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 13:53:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*dict_store_item(char *line, char sep)
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
	key = ft_substr(line, 0, sep_ptr - line);
	if (!key)
		return (NULL);
	value = ft_strdup(sep_ptr + 1);
	if (!value)
	{
		free(key);
		return (NULL);
	}
	item = dict_new(key, value);
	if (!item)
		multi_free(key, value, NULL, NULL);
	return (item);
}
