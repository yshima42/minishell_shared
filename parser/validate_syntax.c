/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:59:25 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 13:27:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//pipe is at end of line, I want to handle as error.
//In bash, Wait standard input.
static bool	validate_pipe_position(t_token *tokens)
{
	t_token	*last;

	if (is_pipe(tokens->kind))
		return (false);
	while (tokens->next != NULL)
	{
		if (is_pipe(tokens->kind) && is_pipe(tokens->next->kind))
			return (false);
		tokens = tokens->next;
	}
	last = tokens;
	if (is_pipe(last->kind))
		return (false);
	return (true);
}

static bool	validate_operator_position(t_token *tokens)
{
	t_token	*last;

	while (tokens->next != NULL)
	{
		if (is_io_operator(tokens->kind) && is_op_kind(tokens->next->kind))
			return (false);
		tokens = tokens->next;
	}
	last = tokens;
	if (is_io_operator(last->kind))
		return (false);
	return (true);
}

bool	validate_syntax(t_token *tokens)
{
	if (!validate_pipe_position(tokens) || \
		!validate_operator_position(tokens))
		return (false);
	return (true);
}
