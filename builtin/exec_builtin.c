/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:20:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 01:16:39 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_pwd(t_info *info)
{
	char	*pwd_path;

	pwd_path = dict_get_value("pwd", info->pwd);
	printf("%s\n", pwd_path);
	g_exit_status = 0;
	return (CONTINUE);
}

int	exec_env(t_dict *env)
{
	g_exit_status = 0;
	show_environment(env, ENV);
	return (CONTINUE);
}

//feel like there is a better way to do this
bool	is_builtin(char **args)
{
	if (!args[0])
		return (false);
	if (ft_strcmp(args[0], "exit") == 0)
		return (true);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (true);
	else if (ft_strcmp(args[0], "export") == 0)
		return (true);
	else if (ft_strcmp(args[0], "unset") == 0)
		return (true);
	else if (ft_strcmp(args[0], "echo") == 0)
		return (true);
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (true);
	else if (ft_strcmp(args[0], "env") == 0)
		return (true);
	else
		return (false);
}

int	exec_builtin(t_proc *proc, t_info *info)
{
	int	exit_flag;

	exit_flag = CONTINUE;
	if (!proc->cmd[0])
		return (exit_flag);
	if (ft_strcmp(proc->cmd[0], "exit") == 0)
		exit_flag = exec_exit(proc->cmd);
	else if (ft_strcmp(proc->cmd[0], "cd") == 0)
		exit_flag = exec_cd(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "export") == 0)
		exit_flag = exec_export(proc->cmd, info->env);
	else if (ft_strcmp(proc->cmd[0], "unset") == 0)
		exit_flag = exec_unset(proc->cmd, info->env);
	else if (ft_strcmp(proc->cmd[0], "pwd") == 0)
		exit_flag = exec_pwd(info);
	else if (ft_strcmp(proc->cmd[0], "env") == 0)
		exit_flag = exec_env(info->env);
	else if (ft_strcmp(proc->cmd[0], "echo") == 0)
		exit_flag = exec_echo(proc->cmd);
	return (exit_flag);
}
