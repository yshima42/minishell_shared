/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:35 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 14:11:57 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	cmd_err(char **cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

static char	*path_from_env(char *cmd, char *strenv)
{
	int		i;
	char	*path;
	char	*ret;
	char	**path_each;

	i = 0;
	path = strenv + 5;
	path_each = ft_xsplit(path, ':');
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
	ft_splitfree(path_each);
	return (0);
}

static char	*get_path(char *cmd, char **sp_cmd, t_info *info)
{
	char		*strenv;

	strenv = mini_getenv("PATH", info);
	if (strenv == NULL)
		xperror("getenv");
	if (access(sp_cmd[0], X_OK) == 0)
		return (sp_cmd[0]);
	else if (ft_strchr(sp_cmd[0], '/'))
	{
		xperror_2comms("minishell: ", cmd);
		return (0);
	}
	else
		return (path_from_env(sp_cmd[0], strenv));
}

void	ft_exec(char **cmd, t_info *info)
{
	char	*path;
	char	**environ;

	if (!cmd[0])
		exit (0);
	environ = xdict_to_array(info->env, "=");
	path = get_path(cmd[0], cmd, info);
	if (execve(path, cmd, environ) == -1)
	{
		free (path);
		cmd_err(cmd);
	}
}
