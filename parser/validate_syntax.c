/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:59:25 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/26 22:59:38 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	validate_pipe_pos(t_token *tokens)
{
	t_token	*last;

	if (is_pipe(tokens->kind))
		return (false);
	while (tokens->next)
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

static bool	validate_operator_pos(t_token *tokens)
{
	t_token	*last;

	while (tokens->next)
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
	if (!*cmd)
		return (count);
	cmd++;
	while (*cmd)
	{
		count++;
		cmd++;
	}
	return (count);
}

bool	validate_syntax(t_token *tokens)
{
	if (!validate_pipe_pos(tokens) || !validate_operator_pos(tokens))
		return (false);
	return (true);
}

bool	validate_arg_num(t_proc *procs)
{
	char	**cur_cmd;

	while (procs)
	{
		cur_cmd = procs->cmd;
		if (count_args(cur_cmd) > MS_ARG_MAX)
			return (false);
		procs = procs->next;
	}
	return (true);
}
