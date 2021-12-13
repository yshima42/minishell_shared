/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_proclist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/08 14:15:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	count_process(t_token *tokens)
{
	size_t	count;

	count = 1;
	while (tokens != NULL)
	{
		if (tokens->kind == PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

t_proc	*init_procinfo(size_t proc_num)
{
	t_proc	*head;
	t_proc	*tmp;
	size_t	idx;

	head = NULL;
	idx = 0;
	while (proc_num--)
	{
		tmp = proc_lstnew();
		proc_lstadd_back(&head, tmp);
	}
	return (head);
}

//Naming
t_proc	*to_proclist(t_token *tokens)
{
	t_proc	*procs;
	size_t	proc_num;

	if (!validate_syntax(tokens))
		return (NULL);
	proc_num = count_process(tokens);
	procs = init_procinfo(proc_num);
	procs = set_procinfo(procs, tokens, proc_num);
	return (procs);
}

int	parse_line(t_proc **proclist, char *line)
{
	t_token	*tokens;

	*proclist = NULL;
	tokens = to_tokenlist(line);
	if (tokens == NULL)
		return (EMPTY_LINE);
	tokens = remove_quote(tokens);
	*proclist = to_proclist(tokens);
	tkn_lstclear(&tokens, free);
	if (*proclist == NULL)
		return (SYNTAX_ERR);
	return (INITIAL_STATE);
}
