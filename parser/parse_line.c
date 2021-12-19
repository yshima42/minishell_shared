/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 11:24:12 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	terminate_syntaxerr(t_token *tokens)
{
	tkn_lstclear(&tokens, free);
	ft_putendl_fd("Syntax Error", STDERR_FILENO);
	return (SYNTAX_ERR);
}

int	parse_line(t_proc **procs, char *line, t_dict *env)
{
	t_token	*tokens;

	*procs = NULL;
	tokens = to_tokenlist(line);
	tokens = expand_var_all(tokens, env);
	tokens = remove_quote(tokens);
	if (tokens == NULL)
	{
		return (EMPTY_LINE);
	}
	if (!validate_syntax(tokens))
	{
		g_exit_status = SYNTAX_ERR;
		return (terminate_syntaxerr(tokens));
	}
	*procs = to_proclist(tokens);
	tkn_lstclear(&tokens, free);
	return (DEFAULT);
}
