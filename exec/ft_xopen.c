/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:55:25 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 00:59:03 by hyoshie          ###   ########.fr       */
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

static int	out_redirect_open(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		perror_2("minishell: ", file);
	return (fd);
}

static int	in_redirect_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror_2("minishell: ", file);
	return (fd);
}

int	ft_xopen(char *file, enum e_kind open_mode, bool is_child)
{
	int	fd;

	if (open_mode == IN_REDIRECT)
		fd = in_redirect_open(file);
	else if (open_mode == OUT_REDIRECT)
		fd = out_redirect_open(file);
	else if (open_mode == APPEND)
		fd = append_open(file);
	else
		fd = 0;
	if (fd == -1 && is_child)
		exit(EXIT_FAILURE);
	return (fd);
}
