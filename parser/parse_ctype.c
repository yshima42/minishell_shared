/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ctype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:53:40 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/06 17:26:31 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_io_operator(enum e_kind kind)
{
	if (kind == HEREDOC || kind == APPEND || \
		kind == IN_REDIRECT || kind == OUT_REDIRECT)
		return (true);
	else
		return (false);
}

bool	is_pipe(enum e_kind kind)
{
	if (kind == PIPE)
		return (true);
	else
		return (false);
}

//Naming
bool	is_op_kind(enum e_kind kind)
{
	if (is_io_operator(kind) || is_pipe(kind))
		return (true);
	else
		return (false);
}

bool	is_cmd(t_token *token)
{
	if (is_op_kind(token->kind))
		return (false);
	if (token->prev != NULL && is_io_operator(token->prev->kind))
		return (false);
	return (true);
}
