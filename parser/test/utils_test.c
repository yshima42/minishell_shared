/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:55:59 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 12:56:23 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"
#include "../parser.h"

void	print_vector(char **vector)
{
	if (vector == NULL)
	{
		printf("[\x1b[32mNULL\x1b[39m]\n");
		return ;
	}
	while (*vector != NULL)
	{
		printf("%s", *vector);
		vector++;
		if (*vector != NULL)
			printf("->");
		else
			printf("\n");
	}
	return ;
}

void	print_iolist(t_io *io_info)
{
	t_io	*tmp;
	char	*kstr[LAST];

	tmp = io_info;
	set_string(kstr);
	while (tmp != NULL)
	{
		printf("[%s]%s", kstr[tmp->kind], tmp->word);
		tmp = tmp->next;
		if (tmp != NULL)
			printf("->");
		else
			printf("\n");
	}
	return ;
}

void	print_procinfo(t_proc *proc, int ex_status)
{
	printf("Proc: %zu\n", proc->id);
	printf("Cmd : ");
	if (proc->cmd == NULL)
		printf("No Commands\n");
	else
		print_vector(proc->cmd);
	printf("IO  : ");
	if (proc->io_info == NULL)
		printf("No Redirect\n");
	else
		print_iolist(proc->io_info);
	printf("$?  : %d\n", ex_status);
	printf("-------------\n");
	return ;
}

void	print_proclist(t_proc *head, int ex_status)
{
	t_proc	*tmp;

	tmp = head;
	printf("-------------\n");
	if (tmp == NULL)
	{
		printf(RED"t_proc == NULL\n"RESET);
		printf("-------------\n");
		return ;
	}
	while (tmp != NULL)
	{
		print_procinfo(tmp, ex_status);
		tmp = tmp->next;
	}
	return ;
}
