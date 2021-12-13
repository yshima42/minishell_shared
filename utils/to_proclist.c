/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_proclist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:35:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/13 20:27:51 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
