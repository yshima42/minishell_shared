/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 20:00:07 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

void	test_parse_line(char *line, char *tstmsg)
{
	t_info	*info;
	t_proc	*procs;
	int		ex_status;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	info = shell_init();
	ex_status = parse_line(&procs, line, info);
	print_proclist(procs, ex_status);
	proc_lstclear(&procs);
	dict_clear(info->env);
	free(info);
	return ;
}

void	test_parse_lines(void)
{
	test_parse_line("ls  -l | cat", "Simple");
	test_parse_line("ls  -l | cat | grep hoge | wc", "Multi Pipe");
	test_parse_line("ls  -l > outfile", "Redirect");
	test_parse_line("ls  -l > outfile | cat < infile", "Pipe and Redirect");
	test_parse_line("echo hoge > a > b > c | cat", "Multi Redirect");
	test_parse_line("echo hoge > a huga > b hugu > c | cat", \
						"Multi Redirect2");
	test_parse_line("< infile cat hoge > a | << end >> a cat", \
						"Multi Redirect3");
	test_parse_line("echo aaa | > hoge | cat", "Only Redirect");
	test_parse_line("", "Empty String");
	test_parse_line("echo aaa > <", "Syntax Error");
	test_parse_line("e\"ch\"o aaa", "Quote");
	test_parse_line("ls ", "Now");
	test_parse_line("echo $?", "Exit Status");
	test_parse_line("echo $HOME$?$HISTSIZE", "Vars");
	return ;
}
