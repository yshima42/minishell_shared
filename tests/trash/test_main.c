/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:50:48 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 14:37:38 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#define TEST_NO 10

void	test_start(t_info *info)
{
	(void)info;
	printf("Start Test\n");
	return ;
}

void	use_funcptr(int idx, t_info *info)
{
	void (*func[TEST_NO])(t_info *info);

	func[0] = test_start;
	func[1] = test_pipe;
	/* func[2] = test_multi_pipes;
	func[3] = test_init_procinfos;
	func[4] = test_set_procinfos; */
	func[idx](info);
	return ;
}

int	main(int argc, char **argv)
{
	int		idx;
	t_info	*info;

	info = shell_init();
	if (argc == 1)
	{
		loop_shell(info);
	}
	else if (argc == 2)
	{
		idx = atoi(argv[1]);
		if (idx < 0 || idx >= TEST_NO)
			exit(EXIT_FAILURE);
		use_funcptr(idx, info);
	}
	dict_clear(info->env);
	return (EXIT_SUCCESS);
}
