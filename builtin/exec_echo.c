/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 07:45:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 10:23:44 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//need to deal with echo $?
int	exec_echo(char **cmd)
{
	size_t	i;
	bool	n_option;

	i = 1;
	n_option = false;
	g_exit_status = 0;
	if (has_no_arg(cmd))
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (0);
	}
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		n_option = true;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i++ + 1] != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (CONTINUE);
}
