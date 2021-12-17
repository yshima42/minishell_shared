/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:23:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/11/01 23:34:49 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c);
static bool	is_sizet(size_t nbr, size_t tmp);

bool	to_nbr(size_t *nbr, const char *nptr)
{
	size_t	tmp;

	*nbr = 0;
	if (!*nptr)
		return (false);
	if (*nptr == '0' && *(nptr + 1))
		return (false);
	while (*nptr)
	{
		tmp = *nptr - '0';
		if (!ft_isdigit(*nptr) || !is_sizet(*nbr, tmp))
			return (false);
		*nbr = *nbr * 10 + tmp;
		nptr++;
	}
	return (true);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_sizet(size_t nbr, size_t tmp)
{
	if (nbr > (SIZE_MAX - tmp) / 10)
		return (false);
	return (true);
}
