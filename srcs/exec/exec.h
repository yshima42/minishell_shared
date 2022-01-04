/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:56:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 17:13:40 by hyoshie          ###   ########.fr       */
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
# include <dirent.h>

# define MAX_PROC 709
# define SUCCESS 0
# define GEN_ERR 1
# define MISUSE_BUILTIN 2
# define EXEC_FAIL 126
# define CMD_NOT_FINED 127
# define PARENT 0
# define CHILD 1

typedef enum e_exit
{
	CONTINUE,
	EXIT
}	t_exit;

void	ft_exec(char **cmd, t_info *info);
void	save_stdfd(t_info *info);
void	close_stdfd(void);
void	pipes_close(int pipes[][2], int num_pipes);
bool	redirect(t_io *io_info);
int		redirect_reset(t_io *io_info, t_info *info);
int		single_proc(t_proc *proc, t_info *info);
int		multi_procs(t_proc *proc, t_info *info);
void	loop_shell(t_info *info);
bool	is_single_proc(t_proc *proc);
bool	is_redirect(t_io *io_info);
bool	is_first_proc(t_proc *proc);
bool	is_last_proc(t_proc *proc);
bool	is_no_cmd(t_proc *proc);
void	xpath_error(char *cmd);
void	xdir_check(char *cmd);
int		ft_open(char *file, enum e_kind open_mode);
void	single_redirect_pipe(t_io *io_info);
bool	launch_shell(t_proc *proc, t_info *info);

#endif
