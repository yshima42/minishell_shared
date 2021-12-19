/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:06:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 14:57:09 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	validate_identifier(char *arg)
{
	if (arg == NULL)
		return (false);
	if (!is_shellvar_top(*arg))
	{
		g_exit_status = 1;
		return (false);
	}
	arg++;
	while (*arg != '\0')
	{
		if (!is_shellvar(*arg))
		{
			g_exit_status = 1;
			return (false);
		}
		arg++;
	}
	return (true);
}

void	puterr_not_validate(char *arg)
{
	ft_putstr_fd("minishell: export: '", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	return ;
}
