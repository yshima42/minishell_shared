/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 08:18:35 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_cd(char **args, t_info *info)
{
	if (args[1] == NULL) //ディレクトリオペランド指定なし
	{
		if (!mini_getenv("HOME", info))
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (CONTINUE);//add error handring
		}
		if (chdir(mini_getenv("HOME", info)) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (CONTINUE);
}
