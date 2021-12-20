/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/20 13:57:14 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	dict_update_value(char *key, char *value, t_dict *dict)
{
	t_dict	*item;

	item = dict_search_item(key, dict);
	if (item == NULL)
		dict_addback(dict, xdict_new(key, value));
	else
	{
		free(key);
		free(item->value);
		item->value = value;
	}
}

bool	is_link(char *operand)
{
	struct stat	sb;

	lstat(operand, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFLNK)
		return (true);
	else
		return (false);
}

bool	is_from_dot(char *operand)
{
	if (operand[0] == '.'||
		(operand[0] == '.' && operand[1] == '.'))
		return (true);
	else
		return (false);
}

bool	is_from_slash(char *operand)
{
	if (operand[0] == '/')
		return (true);
	else
		return (false);
}

/* static void	move_dir(char *operand, t_info *info)
{
	char	*current_path;
	char	*dest_path;

	current_path = ft_strdup(dict_search_item("pwd", info->pwd)->value);
	dest_path = ft_xtrijoin(current_path, "/", operand);

	if (chdir(operand) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(operand);
		g_exit_status = EXIT_FAILURE;
	}
	else
	{
		dict_update_value(ft_strdup("pwd"), dest_path, info->pwd);
		dict_update_value(ft_strdup("oldpwd"), current_path, info->pwd);
		printf("pwd: %s\n", dict_search_item("pwd", info->pwd)->value);
		printf("oldpwd: %s\n", dict_search_item("oldpwd", info->pwd)->value);
		//printf("old_pwd_path: %s\n", dict_get_value("pwd", info->pwd));
		//update_env(ft_strdup("PWD"), pwd_path, ASSIGN,info->env);
		(void)info;
	}
} */

/* static void	operand_cd(char *operand, t_info *info)
{
	char	*home_dir;

	home_dir = mini_getenv("HOME", info);
	move_dir(operand, info);
} */

static void	no_operand_cd(char **operand, char **dest_path, t_info *info)
{
	if (!mini_getenv("HOME", info))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_exit_status = EXIT_FAILURE;
	}
	else
	{
		*operand = ft_strdup(mini_getenv("HOME", info));
		*dest_path = *operand;
	}
}

char	*ft_tailtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*ans;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	ans = ft_substr(s1, 0, end);
	return (ans);
}

int	exec_cd(char **args, t_info *info)
{
	char	*current_path;
	char	*dest_path;
	char	*operand;

	current_path = ft_strdup(dict_search_item("pwd", info->pwd)->value);
	
	if (args[1] == NULL)
		no_operand_cd(&operand, &dest_path, info);
	else
	{
		if (is_from_slash(args[1]))
		{
			operand = ft_strdup(args[1]);
			dest_path = operand;
		}
		/* else if (args[1] == '..')
		{
			dest_path = 
		} */
		else
		{
			operand = ft_tailtrim(args[1], "/");
			dest_path = ft_xtrijoin(current_path, "/", args[1]);
		}
	}

	if (chdir(operand) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(operand);
		g_exit_status = EXIT_FAILURE;
	}
	else
	{
		dict_update_value(ft_strdup("pwd"), dest_path, info->pwd);
		dict_update_value(ft_strdup("oldpwd"), current_path, info->pwd);
		printf("pwd: %s\n", dict_search_item("pwd", info->pwd)->value);
		printf("oldpwd: %s\n", dict_search_item("oldpwd", info->pwd)->value);
		//printf("old_pwd_path: %s\n", dict_get_value("pwd", info->pwd));
		//update_env(ft_strdup("PWD"), pwd_path, ASSIGN,info->env);
		(void)info;
	}
	return (CONTINUE);
}
