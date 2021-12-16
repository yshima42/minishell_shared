/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:56:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 14:16:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_expander.h"

void	test_expand_var(char *word, char *tstmsg)
{
	t_dict	*env;
	char	*expanded;

	printf("TEST: %s\n", tstmsg);
	printf("WORD: "CYAN"%s\n"RESET, word);
	env = init_envs();
	expanded = expand_var(word, env);
	printf("AFT : %s\n\n", expanded);
	dict_clear(env);
	free(expanded);
	return ;
}

void	test_expand_vars(void)
{
	test_expand_var("$HOME", "Simple");
	test_expand_var("$", "$ char");
	test_expand_var("aa$", "$ Char after Chars");
	test_expand_var("$aa", "$ Char before Chars");
	test_expand_var("$HOMEaa", "Var before Chars");
	test_expand_var("aa$HOME", "Var after Chars");
	test_expand_var("\"aa\"$HOME", "Var after DQuart Chars");
	test_expand_var("$HOME\"aa\"", "Var before DQuart Chars");
	test_expand_var("\'aa\'$HOME", "Var after SQuart Chars");
	test_expand_var("$HOME\'aa\'", "Var before SQuart Chars");
	test_expand_var("aa$HOMEbb", "Var between Chars");
	test_expand_var("aa\"$HOME\"bb", "Var in DQuart between Chars");
	test_expand_var("aa\'$HOME\'bb", "Var in SQuart between Chars");
	test_expand_var("$HOME$HISTSIZE", "Two Var");
	test_expand_var("aa$HOME$HISTSIZE", "Two Var after Chars");
	test_expand_var("aa$HOME$HISTSIZEbb", "Two Var Between Chars");
	return ;
}

void	test_expand_exit_status(void)
{
	test_expand_var("$?", "EXITSTATUS");
	test_expand_var("$?aa", "EST before Chars");
	test_expand_var("aa$?", "EST after Chars");
	test_expand_var("\"aa\"$HOME", "EST after DQuart Chars");
	test_expand_var("$?\"aa\"", "EST before DQuart Chars");
	test_expand_var("\'aa\'$?", "EST after SQuart Chars");
	test_expand_var("$?\'aa\'", "EST before SQuart Chars");
	test_expand_var("aa$?bb", "EST between Chars");
	test_expand_var("aa\"$?\"bb", "EST in DQuart between Chars");
	test_expand_var("aa\'$?\'bb", "EST in SQuart between Chars");
	test_expand_var("$?$HISTSIZE", "EST before Var");
	test_expand_var("$HISTSIZE$?", "EST after Var");
	test_expand_var("aa$?$HISTSIZE", "EST-Var after Chars");
	test_expand_var("aa$?$HISTSIZEbb", "EST-Var Between Chars");
	return ;
}
