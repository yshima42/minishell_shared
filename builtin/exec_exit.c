/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:21:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/17 10:45:16 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	is_digitstring(char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	puterr_non_numeric(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	return ;
}

int	exec_exit(char **cmd)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (has_no_arg(cmd))
		return (1);
	if (!is_digitstring(cmd[1]))
	{
		puterr_non_numeric(cmd[1]);
		g_exit_status = 255;
		return (EXIT);
	}
	else if (has_one_arg(cmd))
	{
		g_exit_status = ft_atoi(cmd[1]);
		return (1);
	}
	else
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		g_exit_status = 1;
		return (CONTINUE);
	}
}
