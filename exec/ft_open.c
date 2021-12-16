/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xopen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:09:29 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/16 12:34:22 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	append_xopen(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		xperror(ft_xtrijoin("minishell", ": ", file));
	return (fd);
}

static int	out_redirect_xopen(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		xperror(ft_xtrijoin("minishell", ": ", file));
	return (fd);
}

static int	in_redirect_xopen(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		xperror(ft_xtrijoin("minishell", ": ", file));
	return (fd);
}

//when you xperror, you have to free everything
int	ft_xopen(char *file, enum e_kind open_mode)
{
	if (open_mode == IN_REDIRECT)
		return (in_redirect_xopen(file));
	else if (open_mode == OUT_REDIRECT)
		return (out_redirect_xopen(file));
	else if (open_mode == APPEND)
		return (append_xopen(file));
	else
		return (0);
}
