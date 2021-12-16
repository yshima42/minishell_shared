/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 07:45:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 22:57:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//need to deal with echo $?
int	exec_echo(char **args)
{
	size_t	i;
	bool	n_option;

	i = 1;
	n_option = false;
	g_exit_status = 0;
	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	if (ft_strcmp(args[1], "-n") == 0)
	{
		n_option = true;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i++ + 1] != NULL)
			printf(" ");
	}
	if (n_option == false)
		printf("\n");
	return (0);
}
