/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dict_get_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:52 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 13:37:23 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_expander.h"

void	print_value(char *key, t_dict *dict)
{
	char	*value;

	value = dict_get_value(key, dict);
	printf("[key]%s\n[val]%s\n", key, value);
	printf("\n");
	return ;
}

int	main(void)
{
	t_dict	*dict;

	dict = init_envs();
	print_value("HOME", dict);
	print_value("MAIL", dict);
	print_value("MAILa", dict);
	print_value("NULL", dict);
	dict_clear(dict);
	return (0);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	system("leaks -q get");
}
