/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:55:59 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 11:02:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_is_ifs(void)
{
	printf("%d\n", is_ifs(' '));
	printf("%d\n", is_ifs('a'));
	printf("%d\n", is_ifs('\t'));
	printf("%d\n", is_ifs('\n'));
	return ;
}

void	test_tknlist(void)
{
	t_token	*first;
	t_token	*second;
	t_token	*third;

	first = tkn_lstnew("tkaneshi");
	second = tkn_lstnew("says");
	third = tkn_lstnew("\"review uketara nanntonaku wakattannde\"");
	tkn_lstadd_back(&first, second);
	tkn_lstadd_back(&first, third);
	printf("[1]%s\n", first->word);
	printf("[2]%s\n", first->next->word);
	printf("[3]%s\n", first->next->next->word);
	printf("[1]%s\n", second->prev->word);
	printf("[1]%s\n", third->prev->prev->word);
	return ;
}

void	test_strndup(void)
{
	char	*line;

	line = "abcde";
	printf("line:%6s\n", line);
	printf("%6s, n = %d\n", ft_strndup(line, -1), -1);
	printf("%6s, n = %d\n", ft_strndup(line, 0), 0);
	printf("%6s, n = %d\n", ft_strndup(line, 4), 4);
	printf("%6s, n = %d\n", ft_strndup(line, 5), 5);
	printf("%6s, n = %d\n", ft_strndup(line, 6), 6);
	printf("%6s, n = %d\n", ft_strndup(line, 100), 100);
	return ;
}

void	test_enum_kind(void)
{
	printf("[WORD]%d\n", WORD);
	printf("[HEREDOC]%d\n", HEREDOC);
	printf("[APPEND]%d\n", APPEND);
	printf("[IN_REDIRECT]%d\n", IN_REDIRECT);
	printf("[OUT_REDIRECT]%d\n", OUT_REDIRECT);
	printf("[PIPE]%d\n", PIPE);
	printf("[LAST]%d\n", LAST);
}
