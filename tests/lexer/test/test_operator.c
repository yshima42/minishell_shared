/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 11:22:53 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_lexer.h"

void	test_operator(void)
{
	test_to_token("ls -l | wc", "Simple");
	test_to_token("             ls          -l | wc", "Many space");
	test_to_token("ls\t-l\n| wc", "Newline and Tab");
	test_to_token("ls -l |b wc", "PIPE");
	test_to_token("< infile ls -l | wc > outfile", " < and > ");
	test_to_token("ls -l << heredoc | wc >> outfile", "<< and >>");
	test_to_token("ls -l a<b< heredoc | wc >> outfile", "< and <<");
	test_to_token("", "Empty String");
	test_to_token("ls -l  ><>> hoge", "Consecutive Operator");
	test_to_token("ls ", "After Space");
	test_to_token(" ls", "Before Space");
	test_to_token("\0", "Null Char");
	test_to_token("\n", "New Line");
	return ;
}
