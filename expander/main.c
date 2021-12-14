/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:57:42 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 17:43:08 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test_expander.h"

#define TEST_NO 10

void	call_testfunc(int idx)
{
	void	(*func[TEST_NO])(void);

	func[0] = test_search_prefixs;
	func[1] = test_expand_vars;
	func[2] = test_strclen_arrays;
	func[3] = test_append_nonvars;
	func[4] = test_expand_var_alls;
	func[5] = test_expand_exit_status;
	func[idx]();
	return ;
}

int	main(int argc, char **argv)
{
	int		idx;

	if (argc == 1)
	{
		printf("Try anyting you want.\n");
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

	status = system("leaks -q expander > /dev/null");
	if (status)
		printf(RED"#####Leaks#####\n"RESET);
}
