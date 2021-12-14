/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 11:23:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_lexer.h"

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
