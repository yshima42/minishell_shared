/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:26:42 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/18 01:05:12 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

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

bool	to_longlong(long long *nbr, const char *nptr)
{
	long long	tmp;
	long long	sign;

	*nbr = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
			return (false);
	while (ft_isdigit(*nptr))
	{
		tmp = *nptr - '0';
		if (!is_longlong(*nbr, tmp, sign))
			return (false);
		*nbr = *nbr * 10 + tmp;
		nptr++;
	}
	if (sign == -1)
		*nbr = *nbr * sign;
	return (true);
}

void	test_to_longlong(char *nptr)
{
	long long	nbr;

	nbr = 0;
	if (to_longlong(&nbr, nptr))
		printf("[IN ]%s-> %lld\n", nptr, nbr);
	else
		printf("[OUT]%s-> %lld\n", nptr, nbr);
}

int main(void)
{
	test_to_longlong("0");
	test_to_longlong("2147483647");
	test_to_longlong("2147483648");
	test_to_longlong("-2147483648");
	test_to_longlong("-2147483649");
	test_to_longlong("9223372036854775807");
	test_to_longlong("9223372036854775808");
	test_to_longlong("-9223372036854775808");
	test_to_longlong("-9223372036854775809");
	test_to_longlong("-- 42");
	test_to_longlong("     42       ");
	return (0);
}
