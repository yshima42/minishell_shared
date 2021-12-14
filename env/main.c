/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:51:43 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 20:51:47 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	test_args_check(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
}

void	print_all_env(t_dict *env)
{
	t_dict	*t_env;

	if (env == NULL)
		return ;
	t_env = env->next;
	while (t_env != env)
	{
		printf("key: %s, value: %s\n", t_env->key, t_env->value);
		t_env = t_env->next;
	}
}

int	main(void)
{
	t_info	*info;

	info = shell_init();
	print_all_env(info->env);
	ft_dict_clear(info->env);
	free(info);
	return (0);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	system("leaks -q a.out");
}
