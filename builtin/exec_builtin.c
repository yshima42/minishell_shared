/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:20:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 22:03:51 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_cd(char **args, t_info *info)
{
	if (args[1] == NULL)
	{
		if (chdir(mini_getenv("HOME", info)) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (0);
}

int	exec_pwd(void)
{
	char	pathname[PATHNAME_SIZE];

	ft_memset(pathname, '\0', PATHNAME_SIZE);
	getcwd(pathname, PATHNAME_SIZE);
	printf("%s\n", pathname);
	return (0);
}

int	exec_env(t_info *info)
{
	t_dict	*t_env;

	t_env = info->env->next;
	while (t_env != info->env)
	{	
		printf("%s=%s\n", t_env->key, t_env->value);
		t_env = t_env->next;
	}	
	return (0);
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
		exit_flag = EXIT;
	else if (ft_strcmp(proc->cmd[0], "cd") == 0)
		exit_flag = exec_cd(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "export") == 0)
		exit_flag = exec_export(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "unset") == 0)
		exit_flag = exec_unset(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "pwd") == 0)
		exit_flag = exec_pwd();
	else if (ft_strcmp(proc->cmd[0], "env") == 0)
		exit_flag = exec_env(info);
	else if (ft_strcmp(proc->cmd[0], "echo") == 0)
		exit_flag = exec_echo(proc->cmd, info);
	return (exit_flag);
}
