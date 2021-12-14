/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:57:42 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 12:39:24 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test_lexer.h"

#define TEST_NO 10

void	call_testfunc(int idx)
{
	void	(*func[TEST_NO])(void);

	func[0] = test_operator;
	func[1] = test_quote;
	func[2] = test_strndup;
	func[idx]();
	return ;
}

int	main(int argc, char **argv)
{
	int		idx;

	if (argc == 1)
	{
		printf("Try anyting you want.\n");
		test_to_token("e\"ch\"o aaa", "DQuote Cat");
		test_to_token("e\"ch   \"o aaa", "DQuote Cat");
		test_to_token("e\'ch   \'o aaa", "SQuote Cat");
		test_to_token("e\'cho", "Not Close");
	}
	else if (argc == 2)
	{
		idx = atoi(argv[1]);
		if (idx < 0 || idx >= TEST_NO)
			exit(EXIT_FAILURE);
		call_testfunc(idx);
	}
	return (EXIT_SUCCESS);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	int	status;

	status = system("leaks -q lexer > /dev/null");
	if (status)
		printf(RED"#####Leaks#####\n"RESET);
}
