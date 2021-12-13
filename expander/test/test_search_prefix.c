/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_search_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/12 23:05:29 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_search_prefix(char *word, char *tstmsg)
{
	char	*prefix_pos;

	printf("TEST: %s\n", tstmsg);
	printf("WORD: "CYAN"%s\n"RESET, word);
	prefix_pos = search_prefix(word);
	printf("PFIX: %s\n", prefix_pos);
	printf("\n");
	return ;
}

void	test_search_prefixs(void)
{
	test_search_prefix("aa$HOGEbb", "Simple");
	test_search_prefix("aa$", "$ Character");
	test_search_prefix("aa\"$HOGE\"bb", "IN Double Quart");
	test_search_prefix("aa\'$HOGE\'bb", "IN Single Quart");
	return ;
}
