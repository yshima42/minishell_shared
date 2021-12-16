/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_var_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:56:18 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 14:13:25 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_expander.h"

void	test_expand_var_all(char *line, char *tstmsg)
{
	t_token	*tokens;
	t_token	*expanded;
	t_dict	*env;

	printf("TEST: %s\n", tstmsg);
	printf("WORD: "CYAN"%s\n"RESET, line);
	tokens = to_tokenlist(line);
	env = init_envs();
	printf("BEF : \n");
	print_tokens(tokens);
	expanded = expand_var_all(tokens, env);
	printf("AFT : \n");
	print_tokens(expanded);
	printf("\n");
	tkn_lstclear(&tokens, free);
	dict_clear(env);
	return ;
}

void	test_expand_var_alls(void)
{
	test_expand_var_all("$HOME", "Simple");
	test_expand_var_all("echo $HOME", "Simple Command");
	test_expand_var_all("echo \"$HOME\"", "Var in DQuart");
	test_expand_var_all("echo \'$HOME\'", "Var in SQuart");
	test_expand_var_all("echo aa$HOMEbb", "Var Between Chars");
	test_expand_var_all("echo \"aa$HOMEbb\"", "Var in DQuart Between Chars");
	test_expand_var_all("echo \'aa$HOMEbb\'", "Var in SQuart Between Chars");
	test_expand_var_all("echo aa$HOME$HISTSIZEbb", "Var Between Chars");
	return ;
}
