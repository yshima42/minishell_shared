/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:45:57 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 10:06:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	handler(int sig)
{
	fprintf(stderr, "@");
}

void	handler_42(int sig)
{
	fprintf(stderr, "42tokyo");
}

int	main(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler_42);
	while (1)
	{
		sleep(1);
		fprintf(stderr, ".");
	}
	return (0);
}
