/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:12 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/13 20:27:54 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//delete this later
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

	t_env = env;
	while (t_env->next)
	{
		printf("key: %s, value: %s\n", t_env->key, t_env->value);
		t_env = t_env->next;
	}
}
