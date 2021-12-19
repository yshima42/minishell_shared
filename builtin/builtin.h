/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:35:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/19 17:30:29 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../utils/utils.h"
# include "../parser/parser.h"
# include "../exec/exec.h"

//lstat
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

//PATH_MAX
# include <limits.h>

enum e_symbol
{
	NO_SYMBOL,
	ASSIGN,
	JOIN
};

enum e_cmd
{
	ENV,
	EXPORT
};

int		exec_builtin(t_proc *proc, t_info *info);
bool	is_builtin(char **cmd);
int		exec_echo(char **cmd);
int		exec_export(char **cmd, t_dict *env);
int		exec_unset(char **cmd, t_dict *env);
int		exec_exit(char **cmd);
int		exec_cd(char **args, t_info *info);
//builtin/utils.c
bool	has_no_arg(char **cmd);
bool	has_one_arg(char **cmd);
void	show_environment(t_dict *env, enum e_cmd cmd);
//builtin/export_utils.c
bool	validate_identifier(char *arg);
void	puterr_not_validate(char *arg, char *cmdname);
char	*ft_getcwd(void);
void	update_env(char *key, char *value, enum e_symbol symbol, \
						t_dict *env);

#endif
