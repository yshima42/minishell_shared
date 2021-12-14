/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:56:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 14:42:35 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_expander.h"

void	test_expand_var(char *word, char *tstmsg)
{
	t_info	*info;
	char	*expanded;

	printf("TEST: %s\n", tstmsg);
	printf("WORD: "CYAN"%s\n"RESET, word);
	info = shell_init();
	expanded = expand_var(word, info);
	printf("AFT : %s\n", expanded);
	printf("\n");
	dict_clear(info->env);
	free(info);
	free(expanded);
	return ;
}

void	test_expand_vars(void)
{
	test_expand_var("$HOME", "Simple");
	test_expand_var("$", "$ char");
	test_expand_var("aa$", "$ char after chars");
	test_expand_var("aa$home", "var after chars");
	test_expand_var("aa$HOMEbb", "Var between Chars");
	test_expand_var("aa\"$HOME\"bb", "Var in DQuart between Chars");
	test_expand_var("aa\'$HOME\'bb", "Var in SQuart between Chars");
	test_expand_var("$HOME$HISTSIZE", "Two Var");
	test_expand_var("aa$HOME$HISTSIZE", "Two Var after Chars");
	test_expand_var("aa$HOME$HISTSIZEbb", "Two Var Between Chars");
	return ;
}
