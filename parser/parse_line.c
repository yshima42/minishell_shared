/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 13:29:16 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_line(t_proc **procs, char *line)
{
	t_token	*tokens;

	tokens = to_tokenlist(line);
	if (tokens == NULL)
		return (EMPTY_LINE);
	if (!validate_syntax(tokens))
	{
		tkn_lstclear(&tokens, free);
		return (SYNTAX_ERR);
	}
	tokens = remove_quote(tokens);
	*procs = to_proclist(tokens);
	tkn_lstclear(&tokens, free);
	return (INITIAL_STATE);
}
