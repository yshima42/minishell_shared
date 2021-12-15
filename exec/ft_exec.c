/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:35 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 11:09:37 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*path_from_env(char *cmd, char *strenv)
{
	int		i;
	char	*path;
	char	*ret;
	char	**path_each;

	i = 0;
	path = strenv + 5;
	path_each = ft_split(path, ':');
	i = -1;
	while (path_each[++i])
	{
		ret = ft_strdup(ft_trijoin(path_each[i], "/", cmd));
		if (access(ret, F_OK) == 0)
		{
			ft_splitfree(path_each);
			return (ret);
		}
	}
	ft_splitfree(path_each);
	return (0);
}

char	*get_path(char *cmd, char **sp_cmd, t_info *info)
{
	char		*strenv;

	strenv = mini_getenv("PATH", info);
	if (strenv == NULL)
		xperror("getenv");
	if (access(sp_cmd[0], X_OK) == 0)
		return (sp_cmd[0]);
	else if (ft_strchr(sp_cmd[0], '/'))
	{
		//free(path);
		xperror(ft_trijoin("minishell", ": ", cmd));
		return (0);
	}
	else
		return (path_from_env(sp_cmd[0], strenv));
}

int	ft_exec(char **cmd, t_info *info)
{
	char	*path;
	char	**environ;

	environ = xdict_to_array(info->env, "=");
	path = get_path(cmd[0], cmd, info);
	execve(path, cmd, environ);
	free (path);
	cmd_err(cmd);
	return (0);
}
