/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 22:41:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_splitfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*mini_getenv(const char *key, t_info *info)
{
	t_dict	*t_env;

	t_env = info->env->next;
	while (t_env != info->env)
	{
		if (ft_strcmp(t_env->key, key) == 0)
			return (t_env->value);
		t_env = t_env->next;
	}
	return (NULL);
}
