/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_update_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:03:33 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 15:42:14 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	dict_update_value(char *key, char *new_value, t_dict *dict)
{
	t_dict	*item;

	item = dict_search_item(key, dict);
	if (item == NULL)
		dict_addback(dict, xdict_new(key, new_value));
	else
	{
		free(key);
		free(item->value);
		item->value = new_value;
	}
}
