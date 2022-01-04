/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:00:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 11:21:19 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"
#include "../parser/parser.h"

void	interrupt_heredoc(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(HEREDOC_EXIT);
	return ;
}

void	set_signal_in_heredoc(void)
{
	signal(SIGINT, interrupt_heredoc);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
