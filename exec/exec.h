/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:56:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 14:10:58 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../utils/utils.h"
# include "../parser/parser.h"
# include "../signal/ms_signal.h"
# include "../builtin/builtin.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_PROC 709

typedef enum e_exit
{
	CONTINUE,
	EXIT
}	t_exit;

void	ft_exec(char **cmd, t_info *info);
void	save_stdfd(t_info *info);
void	close_stdfd(void);
void	pipes_close(int pipes[][2], int num_pipes);
void	redirect_pipe(t_io *io_info);
int		redirect_reset(t_io *io_info, t_info *info);
int		ft_xopen(char *file, enum e_kind open_mode);
void	heredoc_handler(t_proc *proc);
int		single_proc(t_proc *proc, t_info *info);
int		multi_procs(t_proc *proc, t_info *info);
int		loop_shell(t_info *info);
bool	launch_shell(t_proc *proc, t_info *info);
bool	is_single_proc(t_proc *proc);
bool	is_redirect(t_io *io_info);
bool	is_first_proc(t_proc *proc);
bool	is_last_proc(t_proc *proc);
bool	is_no_cmd(t_proc *proc);
void	xperror_2comms(char *str1, char *str2);

#endif
