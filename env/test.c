/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:12 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/09 14:42:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//後で消す
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

/* void	print_all_env(t_dict *env) */
/* { */
/* 	t_dict	*t_env; */

/* 	t_env = env; */
/* 	while (t_env->next) */
/* 	{ */
/* 		printf("[\x1b[32mTEST\x1b[39m]\n"); */ 
/* 		printf("key: %s, value: %s\n", t_env->key, t_env->value); */
/* 		t_env = t_env->next; */
/* 	} */
/* } */
