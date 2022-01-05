/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:06:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 23:04:29 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	is_connector(char *arg)
{
	if (*arg == '=' || ft_strnstr(arg, "+=", 2))
		return (true);
	else
		return (false);
}

bool	validate_identifier(char *arg)
{
	if (!is_shellvar_top(*arg))
		return (false);
	arg++;
	while (is_shellvar(*arg))
		arg++;
	if (is_connector(arg) || !*arg)
		return (true);
	else
		return (false);
}

void	puterr_not_validate(char *arg, char *cmdname)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmdname, STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	return ;
}

void	show_declarelist(t_dict *env)
{
	t_dict	*t_env;

	if (!env)
		return ;
	t_env = env->next;
	while (t_env != env)
	{	
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(t_env->key, STDOUT_FILENO);
		if (t_env->value)
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
			ft_putstr_fd(t_env->value, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		t_env = t_env->next;
	}
}

void	show_environlist(t_dict *env)
{
	t_dict	*t_env;

	if (!env)
		return ;
	t_env = env->next;
	while (t_env != env)
	{	
		if (t_env->value)
		{
			ft_putstr_fd(t_env->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(t_env->value, STDOUT_FILENO);
		}
		t_env = t_env->next;
	}
}
