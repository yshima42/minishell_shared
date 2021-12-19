/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:26:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/19 13:23:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_dict	*init_pwd(t_dict *env)
{
	t_dict	*pwd;
	char	*key;
	char	*value;

	pwd = xdict_new("", "");
	key = ft_xstrdup("pwd");
	value = ft_xstrdup(dict_get_value("PWD", env));
	dict_addback(pwd, xdict_new("pwd", value));
	return (pwd);
}

t_info	*shell_init(void)
{
	t_info		*info;
	extern int	g_exit_status;

	info = xmalloc(sizeof(t_info));
	info->env = init_envs();
	info->pwd = init_pwd(info->env);
	save_stdfd(info);
	g_exit_status = 0;
	return (info);
}
