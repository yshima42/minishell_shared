/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:16:24 by hyoshie          ###   ########.fr       */
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

static bool	exists_heredoc(t_proc *proc)
{
	t_io	*current;

	while (proc)
	{
		current = proc->io_info;
		while (current)
		{
			if (current->kind == HEREDOC)
				return (true);
			current = current->next;
		}
		proc = proc->next;
	}
	return (false);
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
	tokens = expand(tokens, env);
	if (!tokens)
		return (EMPTY_LINE);
	*procs = to_proclist(tokens);
	if (exists_heredoc(*procs) && heredoc_handler(*procs) != DEFAULT)
		return (HEREDOC_EXIT);
	return (DEFAULT);
}
