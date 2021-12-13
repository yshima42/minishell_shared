/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:53:45 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 14:57:04 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	proc_lstdelone(t_proc *lst)
{
	if (!lst)
		return ;
	free_vector(lst->cmd);
	io_lstclear(&lst->io_info, free);
	free(lst);
	return ;
}

void	proc_lstclear(t_proc **lst)
{
	t_proc	*tmp;
	t_proc	*current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		proc_lstdelone(current);
		current = tmp;
	}
	*lst = NULL;
	return ;
}
