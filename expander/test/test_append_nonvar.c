/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_append_nonvar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:20:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/10 13:20:03 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.h"

void	test_append_nonvar(char *str, char *tail, size_t len, char *tstmsg)
{
	char	*ret;
	char	*dup;

	printf("TEST: %s\n", tstmsg);
	printf("Str : "CYAN"%s\n"RESET, str);
	printf("Tail: "CYAN"%s\n"RESET, tail);
	printf("Len : "CYAN"%zu\n"RESET, len);
	dup = ft_xstrdup(str);
	ret = append_nonvar(dup, tail, len);
	printf("[ret] %s\n", ret);
	printf("\n");
	free(ret);
	return ;
}

void	test_append_nonvars(void)
{
	test_append_nonvar("42", "tokyo", 5, "Simple");
	test_append_nonvar("42", "tokyo", 4, "Less Size");
	test_append_nonvar("42", "tokyo", 6, "More Size");
	test_append_nonvar("42", "tokyo", INT_MAX, "INT_MAX Size");
	test_append_nonvar("42", "tokyo", 0, "0 Size");
	return ;
}
