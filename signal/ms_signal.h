/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:59:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 01:11:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# include "../libft/mylibft.h"
# include "../utils/utils.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

//signal/signal.c
void	send_newline(int sig);
void	terminate_heredoc(int sig);
void	set_signal_in_read(void);
void	set_signal_in_cmd(void);
void	set_signal_in_heredoc(void);
void	set_signal_ignore(void);
int		display_sig_info(int sig);

#endif /* MS_SIGNAL_H */
