/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/22 00:49:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_lexer.h"

void	set_string(char **kstr)
{
	kstr[0] = "WORD";
	kstr[1] = YELLOW"HERE"RESET;
	kstr[2] = YELLOW"APPE"RESET;
	kstr[3] = YELLOW"IN_ "RESET;
	kstr[4] = YELLOW"OUT_"RESET;
	kstr[5] = YELLOW"PIPE"RESET;
	return ;
}

void	print_tokens(t_token *head)
{
	t_token	*tmp;
	char	*kstr[LAST];

	set_string(kstr);
	if (head == NULL)
	{
		printf(RED"No Token.\n"RESET);
		return ;
	}
	tmp = head;
	while (tmp != NULL)
	{
		printf("[%s]%-8s", kstr[tmp->kind], tmp->word);
		tmp = tmp->next;
		printf("\n");
	}
	return ;
}

void	test_to_token(char *line, char *tstmsg)
{
	t_token	*head;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	head = to_tokenlist(ft_strdup(line));
	print_tokens(head);
	printf("\n");
	tkn_lstclear(&head, free);
	return ;
}
