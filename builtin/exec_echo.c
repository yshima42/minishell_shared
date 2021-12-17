/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 07:45:23 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 10:44:51 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//need to deal with echo $?
int	exec_echo(char **cmd)
{
	size_t	i;
	bool	n_option;

	i = 1;
	n_option = false;
	g_exit_status = 0;
	if (has_no_arg(cmd))
	{
		printf("\n");
		return (0);
	}
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		n_option = true;
		i++;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i++ + 1] != NULL)
			printf(" ");
	}
	if (n_option == false)
		printf("\n");
	return (CONTINUE);
}
