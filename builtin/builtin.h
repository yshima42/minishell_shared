/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:35:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 09:06:57 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../utils/utils.h"
# include "../parser/parser.h"
# include "../exec/exec.h"

# define PATHNAME_SIZE 512

enum e_symbol
{
	NO_SYMBOL,
	ASSIGN,
	JOIN
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
//builtin/export_utils.c
bool	validate_identifier(char *arg);
void	puterr_not_validate(char *arg);
char 	*get_curpath(void);

#endif
