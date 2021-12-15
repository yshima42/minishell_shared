/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 23:08:09 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_dict	*init_envs(void)
{
	char		*key;
	char		*value;
	size_t		i;
	size_t		key_len;
	t_dict		*env;
	extern char	**environ;

	i = 0;
	env = xdict_new("", "");
	while (environ[i])
	{
		key_len = ft_strlen(environ[i]) - ft_strlen(ft_strchr(environ[i], '='));
		key = ft_substr(environ[i], 0, key_len);
		value = ft_strdup(ft_strchr(environ[i], '=') + 1);
		dict_addback(env, dict_new(key, value));
		i++;
	}
	return (env);
}

/* void	del_envs(char *key, t_dict *env)
{
	t_dict	*t_env;
	size_t	i;

	i = 0;
	while ()
	{
		t_env = env->next;
		while (t_env != env)
		{
			if (ft_strcmp(t_env->key, envs[i]) == 0)
				dict_delone(t_env);
			t_env = t_env->next;
		}
		i++;
	}
} */
