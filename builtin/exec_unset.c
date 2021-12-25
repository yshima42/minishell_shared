/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:18:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/25 16:27:37 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	validate_varname(char *arg)
{
	if (!is_shellvar_top(*arg))
		return (false);
	arg++;
	while (is_shellvar(*arg))
		arg++;
	if (!*arg)
		return (true);
	else
		return (false);
}

int	exec_unset(char **cmd, t_dict *env)
{
	t_dict	*item;

	g_exit_status = 0;
	cmd++;
	while (*cmd != NULL)
	{
		if (!validate_varname(*cmd))
		{
			puterr_not_validate(*cmd, "unset");
			g_exit_status = 1;
		}
		else
		{
			item = dict_search_item(*cmd, env);
			if (item && ft_strcmp(item->key, "_") != 0)
				dict_delone(item);
		}
		cmd++;
	}
	return (CONTINUE);
}
