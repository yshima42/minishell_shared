/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_update_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:03:33 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 01:03:34 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	dict_update_value(char *key, char *value, t_dict *dict)
{
	t_dict	*item;

	item = dict_search_item(key, dict);
	if (item == NULL)
		dict_addback(dict, xdict_new(key, value));
	else
	{
		free(key);
		free(item->value);
		item->value = value;
	}
}
