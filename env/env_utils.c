/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 01:50:15 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_dict	*init_envs(void)
{
	char		*key;
	char		*value;
	size_t		key_len;
	t_dict		*env;
	extern char	**environ;

	env = xdict_new("", "");
	while (*environ)
	{
		key_len = ft_strlen(*environ) - ft_strlen(ft_strchr(*environ, '='));
		key = ft_xsubstr(*environ, 0, key_len);
		value = ft_xstrdup(ft_strchr(*environ, '=') + 1);
		dict_addback(env, dict_new(key, value));
		environ++;
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
