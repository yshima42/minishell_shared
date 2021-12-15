/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:59:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 10:46:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# include "../libft/mylibft.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

//signal/signal.c
void	send_newline(int sig);
void	set_signal_in_reading(void);

#endif /* MS_SIGNAL_H */
