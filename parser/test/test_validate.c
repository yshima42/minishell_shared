/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:45:16 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 13:28:10 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

void	test_validate(char *line, char *tstmsg)
{
	t_token	*tokens;

	printf("TEST:  %s\n", tstmsg);
	printf("LINE:  "CYAN"%s\n"RESET, line);
	tokens = to_tokenlist(line);
	if (validate_syntax(tokens))
		printf("Syntax:%s\n", GREEN"OK"RESET);
	else
		printf("Syntax:%s\n", RED"Error"RESET);
	printf("\n");
	tkn_lstclear(&tokens, free);
	return ;
}

void	test_validates(void)
{
	test_validate("ls  -l", "OK");
	test_validate("| ls  -l", "Pipe at first");
	test_validate("ls  -l |", "Pipe at last##Needs Difence##");
	test_validate("< ls  -l", "OK");
	test_validate("ls  -l > log", "OK");
	test_validate("ls  -l > < log", "Consecutive Operator");
	test_validate("ls  -l > > log", "Consecutive Operator");
	test_validate("ls  -l  > |", "Consecutive Operator");
	test_validate("ls  -l <", "Operator at last");
	test_validate("ls  -l <<", "Operator at last");
	test_validate("ls  -l | cat", "OK");
	test_validate("ls  -l || cat", "Consecutive Pipe");
	test_validate("ls  -l | | cat", "Consecutive Pipe");
	return ;
}
