/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_procinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:24:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/06 17:27:46 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_each_procinfo(t_proc *proc, t_token **tokens)
{
	proc->io_info = set_ioinfo(*tokens);
	proc->cmd = set_cmdinfo(tokens);
	return ;
}

t_proc	*set_procinfo(t_proc *procs, t_token *tokens, size_t proc_num)
{
	t_proc	*tmp;
	size_t	idx;

	tmp = procs;
	idx = 0;
	while (proc_num-- > 0)
	{
		set_each_procinfo(tmp, &tokens);
		tmp->id = idx++;
		tmp = tmp->next;
	}
	return (procs);
}
