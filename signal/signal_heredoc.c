/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:00:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 01:43:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"
#include "../parser/parser.h"

void	terminate_heredoc(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDERR_FILENO);
	g_exit_status = 1;
	exit(HEREDOC_ERR);
	return ;
}

void	set_signal_in_heredoc(void)
{
	signal(SIGINT, terminate_heredoc);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
