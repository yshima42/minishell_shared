/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:00:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 01:55:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"

void	terminate_heredoc(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
	return ;
}

void	set_signal_in_heredoc(void)
{
	signal(SIGINT, terminate_heredoc);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
