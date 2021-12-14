/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 22:57:36 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_envs(char **envs, t_info *info)
{
	char		*key;
	char		*value;
	size_t		i;
	size_t		key_len;

	i = 0;
	while (envs[i])
	{
		key_len = ft_strlen(envs[i]) - ft_strlen(ft_strchr(envs[i], '='));
		key = ft_substr(envs[i], 0, key_len);
		value = ft_strdup(ft_strchr(envs[i], '=') + 1);
		dict_addback(info->env, dict_new(key, value));
		i++;
	}
}

void	del_envs(char **envs, t_info *info)
{
	t_dict	*t_env;
	size_t	i;

	i = 0;
	while (envs[i])
	{
		t_env = info->env->next;
		while (t_env != info->env)
		{
			if (ft_strcmp(t_env->key, envs[i]) == 0)
				dict_delone(t_env);
			t_env = t_env->next;
		}
		i++;
	}
}
