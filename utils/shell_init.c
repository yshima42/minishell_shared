/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:26:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 22:57:28 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dict	*init_dict(void)
{
	t_dict	*elem;

	elem = xmalloc(sizeof(t_dict));
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

static void	init_env(t_info *info)
{
	extern char	**environ;
	
	info->env = init_dict();
	add_envs(environ, info);
}

t_info	*shell_init(void)
{
	t_info		*info;

	info = xmalloc(sizeof(t_info));
	init_env(info);
	save_stdfd(info);
	info->exit_status = 0;
	return (info);
}
