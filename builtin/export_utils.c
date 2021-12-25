/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:06:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 16:26:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// bool	validate_identifier(char *arg)
// {
// 	if (arg == NULL)
// 		return (false);
// 	if (!is_shellvar_top(*arg))
// 	{
// 		g_exit_status = 1;
// 		return (false);
// 	}
// 	arg++;
// 	while (*arg != '\0')
// 	{
// 		if (!is_shellvar(*arg))
// 		{
// 			g_exit_status = 1;
// 			return (false);
// 		}
// 		arg++;
// 	}
// 	return (true);
// }

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
