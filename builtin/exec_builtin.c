/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:20:31 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 15:37:56 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	redirect_reset(t_info *info)
{
	xdup2(info->stdfd[SAVED_IN], STDIN_FILENO);
	xdup2(info->stdfd[SAVED_OUT], STDOUT_FILENO);
	xdup2(info->stdfd[SAVED_ERR], STDOUT_FILENO);
}

int	exec_env(t_proc *proc, t_info *info)
{
	t_dict	*t_env;

	(void)proc;//use it later
	t_env = info->env->next;
	while (t_env != info->env)
	{
		//printf("%s=%s\n", t_env->key, t_env->value);
		ft_putstr_fd(t_env->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putstr_fd(t_env->value, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		t_env = t_env->next;
	}
	//need pipe unset because ecec_env is parent 
	return (0);
}

bool	is_builtin(char **args)//feel like there is a better way to do this
{
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
	int	ret;
		
	if (ft_strcmp(proc->cmd[0], "exit") == 0)
		ret = 1;
	else if (ft_strcmp(proc->cmd[0], "cd") == 0)
		ret = exec_cd(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "export") == 0)
		ret = exec_export(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "unset") == 0)
		ret = exec_unset(proc->cmd, info);
	else if (ft_strcmp(proc->cmd[0], "pwd") == 0)
		ret = exec_pwd();
	else if (ft_strcmp(proc->cmd[0], "env") == 0)
		ret = exec_env(proc, info);
	else if (ft_strcmp(proc->cmd[0], "echo") == 0)
		ret = exec_echo(proc->cmd, info);
	else
		ret = EXIT_FAILURE;
	if (is_redirect(proc))
		redirect_reset(info);
	return (ret);
}
