/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/19 13:38:18 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/* void	dict_change_value(char *key, char *value, t_dict *dict)
{
	
	
	if (item != NULL)
	{
		free(key);
		free(item->value);
		item->value = value;
	}
} */

static void	move_dir(char *operand, t_info *info)
{
	//struct stat	sb;

	if (chdir(operand) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(operand);
		g_exit_status = EXIT_FAILURE;
	}
	else
	{
		/* if (lstat(ft_xtrijoin(dict_get_value("pwd", info->pwd), "/", operand), &sb) == 0)
			printf("pwd_path: %s\n", ft_xtrijoin(dict_get_value("pwd", info->pwd), "/", operand));
		else
			printf("pwd_path: %s\n",ft_getcwd()); */
		//update_env(ft_strdup("OLDPWD"), old_pwd_path, ASSIGN, info->env);
		//printf("old_pwd_path: %s\n", dict_get_value("pwd", info->pwd));
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
