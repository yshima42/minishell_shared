/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:23:57 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 12:56:22 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

void	test_count_quote(char *line, char *tstmsg)
{
	size_t	count;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	count = count_quote(line);
	printf("count: %zu\n", count);
	printf("\n");
	return ;
}

void	test_count_quotes(void)
{
	printf(RED"Double Quote\n"RESET);
	test_count_quote("echo aaa", "0:Simple");
	test_count_quote("e\"ch\"o aaa", "1:Simple");
	test_count_quote("\"ech\"o aaa", "1:From Start");
	test_count_quote("e\"ch\"o \'aaa\'", "2:Simple");
	test_count_quote("e\"c\'a\'h\"o aaa", "1:Quote in Quote");
	test_count_quote("e\"cho aaa", "0:Not Closed");
	test_count_quote("e\"cho aaa\'", "0:Different Quote");
	test_count_quote("", "0:Empty String");
	printf(RED"Single Quote\n"RESET);
	test_count_quote("echo aaa", "0:Simple");
	test_count_quote("e\'ch\'o aaa", "1:Simple");
	test_count_quote("\'ech\'o aaa", "1:From Start");
	test_count_quote("e\'ch\'o 'aaa'", "2:Simple");
	test_count_quote("e\'c\"a\"h\'o aaa", "1:Quote in Quote");
	test_count_quote("e\'cho aaa", "0:Not Closed");
	test_count_quote("e\'cho aaa\"", "0:Different Quote");
	test_count_quote("", "0:Empty String");
	return ;
}
