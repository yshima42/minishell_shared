/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 15:32:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_start(void)
{
	printf("Start Parsing\n");
	return ;
}

void	test_count_process(char *line, char *tstmsg)
{
	size_t	count;
	t_token	*tokens;

	printf("TEST:  %s\n", tstmsg);
	printf("LINE:  "CYAN"%s\n"RESET, line);
	tokens = to_tokenlist(line);
	count = count_process(tokens);
	printf("[count]%zu\n", count);
	printf("\n");
	tkn_lstclear(&tokens, free);
	return ;
}

void	test_count_processes(void)
{
	test_count_process("ls -l", "1");
	test_count_process("ls -l | cat aaa", "2");
	test_count_process("ls -l | cat aaa | cat", "3");
	test_count_process("ls -l \"| cat aaa\"", "1");
	return ;
}
