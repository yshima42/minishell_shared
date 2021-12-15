/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 10:58:03 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	loop_shell(t_info *info)
{
	char	*line;
	bool	exit_flag;
	t_proc	*proc;

	exit_flag = 0;
	set_signal_in_reading();
	while (!exit_flag)
	{
		printf("[%d]", info->exit_status);
		line = readline("minishell > ");
		if (line == NULL)
		{
			printf("Catch Ctrl-D\n");
			break ;
		}
		add_history(line);
		info->exit_status = parse_line(&proc, line);
		if (info->exit_status == EMPTY_LINE || info->exit_status == SYNTAX_ERR)
			continue ;
		exit_flag = launch_shell(proc, info);
		free(line);
		free(proc);//need change
	}
	rl_clear_history();
}
