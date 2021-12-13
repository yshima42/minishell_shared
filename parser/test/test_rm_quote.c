/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rm_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:03:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/09 11:02:06 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_rm_quote_word(char *word, char *tstmsg)
{
	char	*new;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, word);
	new = remove_quote_in_token(word);
	printf("[before]%s\n", word);
	printf("[after ]%s\n", new);
	if (new[0] == '\0')
		printf("Exists null charcter.\n");
	printf("\n");
	free(new);
	return ;
}

void	test_rm_quote_words(void)
{
	printf(RED"Double Quote\n"RESET);
	test_rm_quote_word("e\"ch\"o", "Simple");
	test_rm_quote_word("e\"ch \"o", "Simple Space");
	test_rm_quote_word("\"ech\"o", "From Start");
	test_rm_quote_word("e\"c\"a\"h\"o", "2Quote");
	test_rm_quote_word("e\"c\"\"h\"o", "2Quote with No Space");
	test_rm_quote_word("e\"c\'a\'h\"o", "SQuote in DQuote");
	test_rm_quote_word("e\"c\'\'h\"o", "SQuote in DQuote with No space");
	test_rm_quote_word("\"\"", "Only Dquote");
	printf(RED"Single Quote\n"RESET);
	test_rm_quote_word("e\'ch\'o", "Simple");
	test_rm_quote_word("e\'ch \'o", "Simple Space");
	test_rm_quote_word("\'ech\'o", "From Start");
	test_rm_quote_word("e\'c\'a\'h\'o", "2Quote");
	test_rm_quote_word("e\'c\'\'h\'o", "2Quote with No Space");
	test_rm_quote_word("e\'c\"a\"h\'o", "DQuote in SQuote");
	test_rm_quote_word("e\'c\"\"h\'o", "DQuote in SQuote with No Space");
	test_rm_quote_word("\'\'", "Only Squote");
}

void	test_rm_quote(char *line, char *tstmsg)
{
	t_proc	*procs;
	int		ex_status;

	printf("TEST: %s\n", tstmsg);
	printf("LINE: "CYAN"%s\n"RESET, line);
	ex_status = parse_line(&procs, line);
	print_proclist(procs, ex_status);
	proc_lstclear(&procs);
	return ;
}

void	test_rm_quotes(void)
{
	printf(RED"Double Quote\n"RESET);
	test_rm_quote("e\"ch\"o aaa", "Simple");
	test_rm_quote("\"ech\"o aaa", "From Start");
	test_rm_quote("e\"ch\"o aaa > log1 > log2", "Quote and Redirect");
	test_rm_quote("e\"ch\"o aaa \"> log1\" > log2", "Quote 2times1");
	test_rm_quote("e\"ch\"o aaa \"> log1 > log2\"", "Quote 2times2");
	test_rm_quote("e\"ch\"o aaa \"\" > log1", "Quote EmptyString");
	test_rm_quote("e\"ch\"o \"a\'a\'a\" > log1", "SQuote in Dquote");
	test_rm_quote("e\"ch\"o \"a\"a\"a\" > log1", "2Quote");
	test_rm_quote("e\"ch\"o aaa \"l\"o\"g1\"", "2Quote at Last");
	printf(RED"Single Quote\n"RESET);
	test_rm_quote("e\'ch\'o aaa", "Simple");
	test_rm_quote("\'ech\'o aaa", "From Start");
	test_rm_quote("e\'ch\'o aaa > log1 > log2", "Quote and Redirect");
	test_rm_quote("e\'ch\'o aaa \'> log1\' > log2", "Quote 2times1");
	test_rm_quote("e\'ch\'o aaa \'> log1 > log2\'", "Quote 2times2");
	test_rm_quote("e\'ch\'o aaa \'\' > log1", "Quote EmptyString");
	test_rm_quote("e\'ch\'o \'a\"a\"a\' > log1", "DQuote in Squote");
	test_rm_quote("e\'ch\'o \'a\'a\'a\' > log1", "2Quote");
	test_rm_quote("e\'ch\'o aaa \'l\'o\'g1\'", "2Quote at Last");
	return ;
}
