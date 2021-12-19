/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 23:16:44 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	move_dir(char *operand, t_info *info)
{
	char		*old_pwd_path;
	struct stat	sb;

	old_pwd_path = get_pwdpath();
	if (chdir(operand) != 0)
	{
		perror("cd");
		g_exit_status = EXIT_FAILURE;
	}
	else
	{
		if (lstat(ft_xtrijoin(old_pwd_path, "/", operand), &sb) == 0)
			printf("pwd_path: %s\n", ft_xtrijoin(old_pwd_path, "/", operand));
		else
		printf("pwd_path: %s\n",get_pwdpath());
		//update_env(ft_strdup("OLDPWD"), old_pwd_path, ASSIGN, info->env);
		printf("old_pwd_path: %s\n", old_pwd_path);
		free(old_pwd_path);
		//update_env(ft_strdup("PWD"), pwd_path, ASSIGN,info->env);
		(void)info;
	}
}

static void	operand_cd(char *operand, t_info *info)
{
	char	*home_dir;

	home_dir = mini_getenv("HOME", info);
	move_dir(operand, info);
}

static void	no_operand_cd(t_info *info)
{
	if (!mini_getenv("HOME", info))
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	else 
		move_dir(mini_getenv("HOME", info), info);
}

int	exec_cd(char **args, t_info *info)
{
	if (args[1] == NULL)
		no_operand_cd(info);
	else
		operand_cd(args[1], info);
	return (CONTINUE);
}
