/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:29 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 11:09:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_open(char *file, enum e_kind open_mode)
{
	int	fd;
	//when you xperror, you have to free everything
	if (open_mode == IN_REDIRECT)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			xperror(ft_trijoin("minishell", ": ", file));
		return (fd);
	}
	else if (open_mode == OUT_REDIRECT)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
			xperror(ft_trijoin("minishell", ": ", file));
		return (fd);
	}
	else if (open_mode == APPEND)
	{
		fd = open(file, O_WRONLY | O_APPEND, 0666);
		if (fd == -1)
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
			xperror(ft_trijoin("minishell", ": ", file));
		return (fd);
	}	
	else
		return (0);
}
