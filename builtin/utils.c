/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:15:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 17:37:23 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	has_no_arg(char **cmd)
{
	if (cmd == NULL)
		return (false);
	if (cmd[1] == NULL)
		return (true);
	else
		return (false);
}

bool	has_one_arg(char **cmd)
{
	if (cmd == NULL)
		return (false);
	if (cmd[1] == NULL)
		return (false);
	if (cmd[2] == NULL)
		return (true);
	else
		return (false);
}

void	show_environment(t_dict *env, enum e_cmd cmd)
{
	t_dict	*t_env;

	if (env == NULL)
		return ;
	t_env = env->next;
	while (t_env != env)
	{	
		if (cmd == EXPORT)
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(t_env->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		if (t_env->value != NULL)
			ft_putendl_fd(t_env->value, STDOUT_FILENO);
		else
			ft_putchar_fd('\n', STDOUT_FILENO);
		t_env = t_env->next;
	}	
}
