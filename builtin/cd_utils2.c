/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:22:13 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 09:19:10 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	is_link(char *operand)
{
	struct stat	sb;

	lstat(operand, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFLNK)
		return (true);
	else
		return (false);
}

bool	is_from_dot(char *operand)
{
	if (operand[0] == '.'
		|| (operand[0] == '.' && operand[1] == '.'))
		return (true);
	else
		return (false);
}

bool	is_from_slash(char *operand)
{
	if (operand[0] == '/')
		return (true);
	else
		return (false);
}

void	print_error(char *message, char *command)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (command)
	{
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(message, STDERR_FILENO);
	g_exit_status = EXIT_FAILURE;
}

void	cd_perror(char *cmd)
{
	ft_putstr_fd("minishell: cd: ", 2);
	perror(cmd);
	g_exit_status = EXIT_FAILURE;
}
