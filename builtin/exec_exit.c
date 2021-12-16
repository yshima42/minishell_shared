/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:21:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/17 00:56:03 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	is_digitstring(char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	puterr_non_numeric(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	return ;
}

int	exec_exit(char **args)
{
	if (args[1] == NULL)
		return (1);
	if (!is_digitstring(args[1]))
	{
		puterr_non_numeric(args[1]);
		g_exit_status = 255;
		return (1);
	}
	else if (args[2] == NULL)
	{
		g_exit_status = ft_atoi(args[1]);
		return (1);
	}
	else
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		g_exit_status = 1;
		return (0);
	}
}
