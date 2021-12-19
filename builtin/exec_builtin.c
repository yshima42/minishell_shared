/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:20:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 23:27:48 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char *get_pwdpath(void)
{
	char	pathname[PATHNAME_SIZE];
	char	*pwd_path;

	ft_memset(pathname, '\0', PATHNAME_SIZE);
	getcwd(pathname, PATHNAME_SIZE);
	pwd_path = ft_strdup(pathname);
	return (pwd_path);
}

int	exec_pwd(t_info *info)
{
	char	*pwd_path;

	(void)info;
	pwd_path = get_pwdpath();
	printf("%s\n", pwd_path);
	free(pwd_path);
	g_exit_status = 0;
	return (CONTINUE);
}

//info->env == NULL is possible?
int	exec_env(t_info *info)
{
	t_dict	*t_env;

	t_env = info->env->next;
	while (t_env != info->env)
	{	
		ft_putstr_fd(t_env->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		if (t_env->value != NULL)
			ft_putendl_fd(t_env->value, STDOUT_FILENO);
		else
			ft_putchar_fd('\n', STDOUT_FILENO);
		t_env = t_env->next;
	}	
	g_exit_status = 0;
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
		exit_flag = exec_env(info);
	else if (ft_strcmp(proc->cmd[0], "echo") == 0)
		exit_flag = exec_echo(proc->cmd);
	return (exit_flag);
}
