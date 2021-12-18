/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 09:51:41 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	move_dir(char *operand)
{
	if (chdir(operand) != 0)
		perror("cd");
}

static void	operand_cd(char *operand, t_info *info)
{
	char	*ope_tmp;
	char	*home_dir;

	home_dir = mini_getenv("HOME", info);
	if (operand[0] == '~')
	{
		ope_tmp = ft_xstrjoin(home_dir, &operand[1]);
		move_dir(ope_tmp);
		free (ope_tmp);
	}
	else
		move_dir(operand);
}

static void	no_operand_cd(t_info *info)
{
	if (!mini_getenv("HOME", info))
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	else 
		if (chdir(mini_getenv("HOME", info)) != 0)
			perror("cd");//ここをoperandにつなぐか検討
}

int	exec_cd(char **args, t_info *info)
{
	if (args[1] == NULL)
		no_operand_cd(info);
	else
		operand_cd(args[1], info);
	return (CONTINUE);
}
