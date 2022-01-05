/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_procinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:24:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/26 23:05:55 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_each_procinfo(t_proc *proc, t_token **tokens)
{
	proc->io_info = set_ioinfo(*tokens);
	proc->cmd = set_cmdinfo(tokens);
}

t_proc	*set_procinfo(t_proc *procs, t_token *tokens, size_t proc_num)
{
	t_proc	*current;
	size_t	idx;

	current = procs;
	idx = 0;
	while (proc_num--)
	{
		set_each_procinfo(current, &tokens);
		current->id = idx++;
		current = current->next;
	}
	return (procs);
}
