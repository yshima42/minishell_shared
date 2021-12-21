/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:59:25 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 10:37:39 by hyoshie          ###   ########.fr       */
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

size_t	count_args(char **cmd)
{
	size_t	count;

	count = 0;
	if (*cmd == NULL)
		return (count);
	cmd++;
	while (*cmd != NULL)
	{
		count++;
		cmd++;
	}
	return (count);
}

bool	validate_syntax(t_token *tokens)
{
	if (!validate_pipe_position(tokens) || \
		!validate_operator_position(tokens))
		return (false);
	return (true);
}

bool	validate_arg_num(t_proc *procs)
{
	char	**tmp_cmd;

	while (procs != NULL)
	{
		tmp_cmd = procs->cmd;
		if (count_args(tmp_cmd) > MS_ARG_MAX)
			return (false);
		procs = procs->next;
	}
	return (true);
}
