/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:00:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 10:45:26 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"

void	send_newline(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	set_signal_in_reading(void)
{
	signal(SIGINT, send_newline);
	signal(SIGQUIT, SIG_IGN);
}
