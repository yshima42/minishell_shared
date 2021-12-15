/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:45:57 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 09:52:41 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	handler(int sig)
{
	fprintf(stderr, "@");
}

int	main(void)
{
	signal(SIGINT, handler);
	while (1)
	{
		sleep(1);
		fprintf(stderr, ".");
	}
	return (0);
}
