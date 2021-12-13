/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:14:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/12 19:24:49 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

/* void	add_envs(char **envs, t_info *info) */
/* { */
/* 	char		*key; */
/* 	char		*value; */
/* 	size_t		i; */
/* 	size_t		key_len; */

/* 	i = 0; */
/* 	while (envs[i]) */
/* 	{ */
/* 		key_len = ft_strlen(envs[i]) - ft_strlen(ft_strchr(envs[i], '=')); */ 
/* 		key = ft_substr(envs[i], 0, key_len); */
/* 		printf("[key]%s\n", key); */
/* 		value = ft_strdup(ft_strchr(envs[i], '=') + 1); */
/* 		ft_dictadd_back(info->env, ft_dictnew(key, value)); */
/* 		i++; */
/* 	} */
/* 	printf("[info->env->key]%s\n", info->env->key); */
/* 	printf("[info->env->value]%s\n", info->env->value); */
/* 	printf("[\x1b[32mOK\x1b[39m]\n"); */
/* } */

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
