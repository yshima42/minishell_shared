/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_proclist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 01:08:46 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_process(t_token *tokens)
{
	size_t	count;

	count = 1;
	while (tokens)
	{
		if (tokens->kind == PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

static t_proc	*init_procinfo(size_t proc_num)
{
	t_proc	*head;
	t_proc	*current;

	head = NULL;
	while (proc_num--)
	{
		current = proc_lstnew();
		proc_lstadd_back(&head, current);
	}
	return (head);
}

//Naming
t_proc	*to_proclist(t_token *tokens)
{
	t_proc	*procs;
	size_t	proc_num;
	t_token	*head;

	head = tokens;
	proc_num = count_process(tokens);
	procs = init_procinfo(proc_num);
	procs = set_procinfo(procs, tokens, proc_num);
	tkn_lstclear(&head, free);
	return (procs);
}
