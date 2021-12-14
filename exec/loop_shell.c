/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 14:39:34 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* char	**shell_split_line(char *line)
{
	char	**tokens;

	//char	*token;
	tokens = ft_split(line, '|');
	return (tokens);
	//token = ft_strtok(line);
} */

void	loop_shell(t_info *info)
{
	char	*line;
	bool	exit_flag;
	t_proc	*proc;

	exit_flag = 0;
	while (!exit_flag)
	{
		line = readline("minishell > ");
		info->exit_status = parse_line(&proc, line);//change later
		exit_flag = launch_shell(proc, info);
		free(line);
		free(proc);//need change
	}
}
