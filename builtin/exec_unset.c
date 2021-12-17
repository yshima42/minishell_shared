/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:18:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 19:36:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_unset(char **cmd, t_dict *env)
{
	t_dict	*item;

	g_exit_status = 0;
	cmd++;
	while (*cmd != NULL)
	{
		item = dict_search_item(*cmd, env);
		if (item != NULL && ft_strcmp(item->key, "_") != 0)
			dict_delone(item);
		cmd++;
	}
	return (CONTINUE);
}
