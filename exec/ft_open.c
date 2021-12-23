/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:26:11 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 00:11:59 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	append_open(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		perror_2("minishell: ", file);
	return (fd);
}

static int	out_redirect_xopen(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		perror_2("minishell: ", file);
	return (fd);
}

static int	in_redirect_xopen(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror_2("minishell: ", file);
	return (fd);
}

int	ft_open(char *file, enum e_kind open_mode)
{
	if (open_mode == IN_REDIRECT)
		return (in_redirect_xopen(file));
	else if (open_mode == OUT_REDIRECT)
		return (out_redirect_xopen(file));
	else if (open_mode == APPEND)
		return (append_open(file));
	else
		return (0);
}
