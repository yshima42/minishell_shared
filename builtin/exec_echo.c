/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 07:45:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/13 22:01:41 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//need to deal with echo $?
int	exec_echo(char **args, t_info *info)
{
	size_t	i;
	bool	n_option;
	
	i = 1;
	n_option = false;
	if (!args[1])
	{
		printf("\n");
		return (1);
	}
	if (ft_strcmp(args[1], "-n") == 0)
	{
		n_option = true;
		i++;
	}
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			printf("%s", mini_getenv(args[i] + 1, info));
		}
		else
		{
			printf("%s", args[i]);
			if (args[i + 1] != NULL)
				printf(" ");
		}
		i++;
	}
	if (n_option == false)
		printf("\n");
	return (1);
}
