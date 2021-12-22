/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/23 00:55:09 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	terminate_syntaxerr(t_token *tokens)
{
	g_exit_status = SYNTAX_ERR;
	tkn_lstclear(&tokens, free);
	ft_putendl_fd("minishell: syntax Error", STDERR_FILENO);
	return (SYNTAX_ERR);
}

static bool	exists_heredoc(t_proc *proc)
{
	t_io	*tmp;

	while (proc != NULL)
	{
		tmp = proc->io_info;
		while (tmp != NULL)
		{
			if (tmp->kind == HEREDOC)
				return (true);
			tmp = tmp->next;
		}
		proc = proc->next;
	}
	return (false);
}

static t_token	*expand_tokens(t_token *tokens, t_dict *env)
{
	t_token	*new;

	new = expand_var_all(tokens, env);
	new = split_expanded_word(new);
	new = remove_quote(new);
	if (!new)
		g_exit_status = 0;
	return (new);
}

int	parse_line(t_proc **procs, char *line, t_dict *env)
{
	t_token	*tokens;

	*procs = NULL;
	tokens = to_tokenlist(line);
	if (tokens == NULL)
	{
		free(line);
		return (EMPTY_LINE);
	}
	add_history(line);
	free(line);
	if (!validate_syntax(tokens))
		return (terminate_syntaxerr(tokens));
	tokens = expand_tokens(tokens, env);
	if (tokens == NULL)
		return (EMPTY_LINE);
	*procs = to_proclist(tokens);
	if (exists_heredoc(*procs) && heredoc_handler(*procs) != DEFAULT)
		return (HEREDOC_EXIT);
	return (DEFAULT);
}
