/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/13 20:49:33 by yshimazu         ###   ########.fr       */
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
	int		status;
	t_proc	*proc;

	status = 1;
	while (true)
	{
		if (!status)
			break ;
		#include <stdio.h>
		line = readline("minishell > ");
		status = parse_line(&proc, line);//change later
		status = exec_shell(proc, info);
		free(line);
		free(proc);//need change
	}
}
