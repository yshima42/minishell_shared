/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 18:25:08 by hyoshie          ###   ########.fr       */
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

int	parse_line(t_proc **procs, char *line, t_dict *env)
{
	t_token	*tokens;

	*procs = NULL;
	tokens = to_tokenlist(line);
	if (tokens == NULL)
		return (EMPTY_LINE);
	tokens = expand_var_all(tokens, env);
	tokens = split_expanded_word(tokens);
	tokens = remove_quote(tokens);
	if (tokens == NULL)
		return (EMPTY_LINE);
	if (!validate_syntax(tokens))
		return (terminate_syntaxerr(tokens));
	*procs = to_proclist(tokens);
	tkn_lstclear(&tokens, free);
	if (exists_heredoc(*procs) && heredoc_handler(*procs) != DEFAULT)
		return (HEREDOC_EXIT);
	return (DEFAULT);
}
