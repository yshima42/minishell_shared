/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:35 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 18:05:57 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	cmd_err(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(CMD_NOT_FINED);
}

static char	*path_from_env(char *cmd, char *envpath)
{
	int		i;
	char	*ret;
	char	**path_each;

	path_each = ft_xsplit(envpath, ':');
	if (*path_each == NULL)
		return (cmd);
	i = -1;
	while (path_each[++i])
	{
		ret = ft_xstrdup(ft_xtrijoin(path_each[i], "/", cmd));
		if (access(ret, F_OK) == 0)
		{
			ft_splitfree(path_each);
			return (ret);
		}
	}
	cmd_err(cmd);
	ft_splitfree(path_each);
	return (0);
}

static char	*get_path(char *cmd, char **cmd_array, t_info *info)
{
	char		*envpath;

	envpath = mini_getenv("PATH", info);
	if (envpath == NULL || ft_strchr(cmd_array[0], '/'))
	{
		xdir_check(cmd);
		return (cmd_array[0]);
	}
	else
		return (path_from_env(cmd_array[0], envpath));
}

void	ft_exec(char **cmd, t_info *info)
{
	char	*path;
	char	**environ;

	if (!cmd[0])
		exit (0);
	if (!cmd[0][0])
	{
		cmd_err(cmd[0]);
		return ;
	}
	environ = xdict_to_array(info->env, "=");
	path = get_path(cmd[0], cmd, info);
	if (execve(path, cmd, environ) == -1)
	{
		free (path);
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(*cmd);
		exit(EXEC_FAIL);
	}
}
