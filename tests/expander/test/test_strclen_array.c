/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclen_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:20:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 14:42:55 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_expander.h"

void	test_strclen_array(char *str, char *sep, char *tstmsg)
{
	size_t	len;

	printf("TEST: %s\n", tstmsg);
	printf("Str: "CYAN"%s\n"RESET, str);
	printf("Sep: "CYAN"%s\n"RESET, sep);
	len = ft_strclen_array(str, sep);
	printf("[len]%zu\n", len);
	printf("\n");
	return ;
}

void	test_strclen_arrays(void)
{
	test_strclen_array("42tokyo", "t", "2:Simple");
	test_strclen_array("42tokyo", "abc", "7:Nothing");
	test_strclen_array("42tokyo", "abcy", "5:In Last");
	test_strclen_array("42tokyo", "aybc", "5:In Third");
	test_strclen_array("42tokyo", "yabc", "5:In First");
	test_strclen_array("42\"tokyo\"", "abc\"", "2:[Symbol]In Last");
	test_strclen_array("42\"toky\"o", "a\"bc", "2:[Symbol]In Third");
	test_strclen_array("42\"toky\"o", "\"abc", "2:[Symbol]In First");
	return ;
}
