/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:21:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/22 23:41:11 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "builtin.h"

static bool	is_longlong(long long nbr, long long tmp, int sign)
{
	long long	mod;
	long long	div;

	mod = LLONG_MAX % 10;
	div = LLONG_MAX / 10;
	if ((nbr > div || ((nbr == div && tmp > mod))) && sign == 1)
		return (false);
	if ((nbr > div || (nbr == div && tmp > mod + 1)) && sign == -1)
		return (false);
	return (true);
}

static void	set_sign(long long *sign, char **nptr)
{
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			*sign = -1;
		*nptr += 1;
	}
}

static bool	to_longlong(long long *nbr, char *nptr)
{
	long long	sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	set_sign(&sign, &nptr);
	if (!ft_isdigit(*nptr))
		return (false);
	while (ft_isdigit(*nptr))
	{
		if (!is_longlong(*nbr, *nptr - '0', sign))
			return (false);
		*nbr = *nbr * 10 + (*nptr - '0');
		nptr++;
	}
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr != '\0')
		return (false);
	if (sign == -1)
		*nbr = *nbr * sign;
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
	long long	exit_num;

	ft_putendl_fd("exit", STDERR_FILENO);
	exit_num = 0;
	if (has_no_arg(cmd))
		return (EXIT);
	if (!to_longlong(&exit_num, cmd[1]))
	{
		puterr_non_numeric(cmd[1]);
		g_exit_status = 255;
		return (EXIT);
	}
	else if (has_one_arg(cmd))
	{
		g_exit_status = exit_num;
		return (EXIT);
	}
	else
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		g_exit_status = 1;
		return (CONTINUE);
	}
}
