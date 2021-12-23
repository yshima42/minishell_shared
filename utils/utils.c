/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/23 23:54:06 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//change to stdfd
void	save_stdfd(t_info *info)
{
	info->stdfd[SAVED_IN] = xdup(STDIN_FILENO);
	info->stdfd[SAVED_OUT] = xdup(STDOUT_FILENO);
	info->stdfd[SAVED_ERR] = xdup(STDERR_FILENO);
}

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

//move to builtin?
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

void	ms_puterr_2arg(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str2, STDERR_FILENO);
}

void	xperror_2(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	xperror(str2);
}
