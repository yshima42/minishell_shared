/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 17:04:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	terminate_syntaxerr(t_token *tokens)
{
	tkn_lstclear(&tokens, free);
	ft_putendl_fd("Syntax Error", STDERR_FILENO);
	return (SYNTAX_ERR);
}

int	parse_line(t_proc **procs, char *line)
{
	t_token	*tokens;

	tokens = to_tokenlist(line);
	if (tokens == NULL)
		return (EMPTY_LINE);
	if (!validate_syntax(tokens))
		return (terminate_syntaxerr(tokens));
	tokens = remove_quote(tokens);
	*procs = to_proclist(tokens);
	tkn_lstclear(&tokens, free);
	return (INITIAL_STATE);
}
