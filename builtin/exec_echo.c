/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 07:45:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 11:09:28 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	has_n_option(char *cmd)
{
	if (ft_strncmp(cmd, "-n", 2) == 0)
		cmd += 2;
	while (*cmd == 'n')
		cmd++;
	if (*cmd == '\0')
		return (true);
	else
		return (false);
}

void	skip_optins(char **cmd, size_t *i)
{
	while (has_n_option(cmd[*i]))
		(*i)++;
}

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
	if (has_n_option(cmd[1]))
	{
		n_option = true;
		skip_optins(cmd, &i);
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
