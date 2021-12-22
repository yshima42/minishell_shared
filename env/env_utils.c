/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 18:51:29 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_dict	*init_envs(void)
{
	char		*key;
	char		*value;
	size_t		i;
	t_dict		*env;
	extern char	**environ;

	env = xdict_new("", "");
	i = 0;
	while (environ[i])
	{
		key = ft_xsubstr(environ[i], 0, ft_strclen(environ[i], '='));
		value = ft_xstrdup(ft_strchr(environ[i], '=') + 1);
		dict_addback(env, dict_new(key, value));
		i++;
	}
	dict_delone(dict_search_item("OLDPWD", env));
	return (env);
}
