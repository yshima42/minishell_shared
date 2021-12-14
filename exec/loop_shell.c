/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 20:59:26 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	loop_shell(t_info *info)
{
	char	*line;
	bool	exit_flag;
	t_proc	*proc;

	exit_flag = 0;
	while (!exit_flag)
	{
		line = readline("minishell > ");
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
