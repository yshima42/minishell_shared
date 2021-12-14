/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:57:42 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 12:38:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.h"

#define TEST_NO 10

void	use_funcptr(int idx)
{
	void	(*func[TEST_NO])(void);

	func[0] = test_start;
	func[1] = test_count_processes;
	func[2] = test_validates;
	func[3] = test_init_procinfos;
	func[4] = test_set_procinfos;
	func[5] = test_rm_quotes;
	func[6] = test_count_quotes;
	func[7] = test_rm_quote_words;
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
		use_funcptr(idx);
	}
	return (EXIT_SUCCESS);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	int	status;

	status = system("leaks -q parser > /dev/null");
	if (status)
		printf(RED"#####Leaks#####\n"RESET);
}
