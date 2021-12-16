/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 16:38:08 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

void	test_set_procinfo(char *line, char *tstmsg)
{
	t_proc	*procs;
	t_dict	*env;
	int		ex_status;

	env = init_envs();
	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	ex_status = parse_line(&procs, line, env);
	print_proclist(procs, ex_status);
	proc_lstclear(&procs);
	dict_clear(env);
	return ;
}

void	test_set_procinfos(void)
{
	test_set_procinfo("ls  -l | cat", "Simple");
	test_set_procinfo("ls  -l | cat | grep hoge | wc", "Multi Pipe");
	test_set_procinfo("ls  -l > outfile", "Redirect");
	test_set_procinfo("ls  -l > outfile | cat < infile", "Pipe and Redirect");
	test_set_procinfo("echo hoge > a > b > c | cat", "Multi Redirect");
	test_set_procinfo("echo hoge > a huga > b hugu > c | cat", \
						"Multi Redirect2");
	test_set_procinfo("< infile cat hoge > a | << end >> a cat", \
						"Multi Redirect3");
	test_set_procinfo("echo aaa | > hoge | cat", "Only Redirect");
	test_set_procinfo("", "Empty String");
	test_set_procinfo("echo aaa > <", "Syntax Error");
	test_set_procinfo("e\"ch\"o aaa", "Quote");
	test_set_procinfo("$HOME", "Only Env-var");
	test_set_procinfo("$HOMEa", "Nothing");
	test_set_procinfo("ls $HOMEa", "Only ls");
	test_set_procinfo("$HOMEa ls", "Only ls");
	return ;
}
