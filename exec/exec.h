/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:56:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 17:51:13 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "../utils/utils.h"
#include "../parser/parser.h"

int		ft_exec(char **cmd, t_info *info);
void	save_stdfd(t_info *info);
void	close_stdfd(void);
void	pipes_close(int pipes[][2], int num_pipes);
void	redirect_pipe(t_io *io_info, t_info *info);
int		redirect_reset(t_io *io_info, t_info *info);
int		ft_open(char *file, enum e_kind open_mode);
void	heredoc_handler(t_io *io_info, t_info *info);
int		single_proc(t_proc *proc, t_info *info);
int		exec_multi_procs(t_proc *proc, t_info *info);
void	loop_shell(t_info *info);
bool	launch_shell(t_proc *proc, t_info *info);
bool	is_single_proc(t_proc *proc);
bool	is_redirect(t_io *io_info);
bool	is_first_proc(t_proc *proc);
bool	is_last_proc(t_proc *proc);
bool	is_no_cmd(t_proc *proc);

#endif
