/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/13 01:30:30 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
	head = to_tokenlist(line);
	print_tokens(head);
	printf("\n");
	tkn_lstclear(&head, free);
	return ;
}

void	test_operator(void)
{
	// test_to_token("ls -l | wc", "Simple");
	// test_to_token("             ls          -l | wc", "Many space");
	// test_to_token("ls\t-l\n| wc", "Newline and Tab");
	// test_to_token("ls -l |b wc", "PIPE");
	// test_to_token("< infile ls -l | wc > outfile", " < and > ");
	// test_to_token("ls -l << heredoc | wc >> outfile", "<< and >>");
	// test_to_token("ls -l a<b< heredoc | wc >> outfile", "< and <<");
	// test_to_token("", "Empty String");
	// test_to_token("ls -l  ><>> hoge", "Consecutive Operator");
	test_to_token("ls ", "Now ");
	test_to_token("ls -a", "Now ");
	test_to_token("\0", "Null Char");
	test_to_token("\n", "New Line");
	return ;
}

void	test_quote(void)
{
	test_to_token("echo aaa  | wc -l", "Simple");
	printf(RED"Double Quote\n"RESET);
	test_to_token("echo aaa \" | wc \" -l", "Enclose Pipe");
	test_to_token("echo \"aaa >> log\"", "Enclose Append");
	test_to_token("echo \"aaa << log\"", "Enclose Heredoc");
	test_to_token("echo \"aaa > log\"", "Enclose OUT_Redirect");
	test_to_token("echo \"aaa < log\"", "Enclose IN_Redirect");
	test_to_token("\"echo aaa \">> log", "Enclose from Start");
	test_to_token("echo \"aaa >> log", "Failed to Enclose");
	test_to_token("e\"ch\"o aaa", "Quote Cat");
	
	printf(RED"Single Quote\n"RESET);
	test_to_token("echo aaa \' | wc \' -l", "Enclose Pipe");
	test_to_token("echo \'aaa >> log\'", "Enclose Append");
	test_to_token("echo \'aaa << log\'", "Enclose Heredoc");
	test_to_token("echo \'aaa > log\'", "Enclose OUT_Redirect");
	test_to_token("echo \'aaa < log\'", "Enclose IN_Redirect");
	test_to_token("\'echo aaa \'>> log", "Enclose from Start");
	test_to_token("echo \'aaa >> log", "Failed to Enclose");
	test_to_token("e\'ch   \'o aaa", "Quote Cat");
}
