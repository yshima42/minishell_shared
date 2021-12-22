/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/22 01:06:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

void	test_init_procinfo(char *line, char *tstmsg)
{
	t_token	*tokens;
	t_proc	*procs;
	size_t	count;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	tokens = to_tokenlist(line);
	count = count_process(tokens);
	procs = init_procinfo(count);
	print_proclist(procs, DEFAULT);
	proc_lstclear(&procs);
	tkn_lstclear(&tokens, free);
	return ;
}

void	test_init_procinfos(void)
{
	test_init_procinfo("ls  -l | cat", "Simple");
	test_init_procinfo("ls  -l | cat | grep hoge | wc", "Many Process");
	return ;
}
