/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:00:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 01:43:27 by hyoshie          ###   ########.fr       */
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
	g_exit_status = 1;
	return ;
}

void	set_signal_in_read(void)
{
	signal(SIGINT, send_newline);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

void	set_signal_in_cmd(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return ;
}

void	set_signal_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

int	display_sig_info(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (sig == SIGQUIT)
	{
		ft_putendl_fd("Quit: 3", STDERR_FILENO);
	}
	return (sig + 128);
}
