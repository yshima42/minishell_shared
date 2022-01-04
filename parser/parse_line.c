/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 01:16:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	terminate_syntaxerr(t_token *tokens)
{
	g_exit_status = SYNTAX_ERR;
	tkn_lstclear(&tokens, free);
	ft_putendl_fd("minishell: Syntax Error", STDERR_FILENO);
	return (SYNTAX_ERR);
}

int	parse_line(t_proc **procs, char *line, t_dict *env)
{
	t_token	*tokens;

	*procs = NULL;
	tokens = to_tokenlist(line);
	if (!tokens)
		return (EMPTY_LINE);
	if (!validate_syntax(tokens))
		return (terminate_syntaxerr(tokens));
	if (heredoc_handler(tokens) != DEFAULT)
		return (HEREDOC_EXIT);
	tokens = expand(tokens, env);
	if (!tokens)
		return (EMPTY_LINE);
	*procs = to_proclist(tokens);
	return (DEFAULT);
}
