/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/21 17:44:24 by hyoshie          ###   ########.fr       */
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

	i = 0;
	env = xdict_new("", "");
	while (environ[i])
	{
		key = ft_xsubstr(environ[i], 0, ft_strclen(environ[i], '='));
		value = ft_xstrdup(ft_strchr(environ[i], '=') + 1);
		dict_addback(env, dict_new(key, value));
		i++;
	}
	return (env);
}
