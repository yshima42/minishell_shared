/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/23 15:19:16 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_cmdline(char *cmd_line, t_info *info)
{
	t_proc	*proc;
	char	**cmd_array;
	size_t	i;
	
	i = 0;
	cmd_array = ft_split(cmd_line, ';');
	while (cmd_array[i])
	{
		set_signal_in_read();
		parse_line(&proc, cmd_array[i], info->env);
		launch_shell(proc, info);
		i++;
	}
	free(cmd_array);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	info = shell_init();
	if (argc > 2 && ft_strcmp("-c", argv[1]) == 0)
		run_cmdline(argv[2], info);
	else
		loop_shell(info);
	shell_terminate(info);
	return (g_exit_status);
}
