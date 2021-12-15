/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:56:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 16:08:33 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct	s_info t_info;

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

#endif
