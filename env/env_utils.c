/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 16:30:55 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	shlvl_update(t_dict *env)
{
	int	shlvl;

	shlvl = ft_atoi(dict_get_value("SHLVL", env));
	shlvl++;
	if (shlvl > 1000)
	{
		ft_putstr_fd("bash: warning: shell level (1000) too high, \
		resetting to 1", STDERR_FILENO);
		shlvl = 1;
	}
	dict_update_value(ft_xstrdup("SHLVL"), ft_itoa(shlvl), env);
}

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
	shlvl_update(env);
	dict_delone(dict_search_item("OLDPWD", env));
	dict_delone(dict_search_item("_", env));
	return (env);
}
