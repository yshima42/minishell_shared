/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:29:27 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/13 20:26:29 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	xperror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	xpipe(int *fd)
{
	if (pipe(fd) == -1)
		xperror("pipe");
}

//use kill in xfork
pid_t	xfork(void)
{
	pid_t	ret;

	ret = fork();
	if (ret < 0)
		xperror("fork");
	return (ret);
}

void	xdup2(int fd1, int fd2)
{
	int	ret;

	ret = dup2(fd1, fd2);
	if (ret == -1)
		xperror("dup2");
}