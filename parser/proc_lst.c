/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:10:51 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 14:00:56 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_proc	*proc_lstnew(void)
{
	t_proc	*new;

	new = (t_proc *)xmalloc(sizeof(t_proc));
	new->prev = NULL;
	new->next = NULL;
	new->cmd = NULL;
	new->io_info = NULL;
	new->id = 0;
	return (new);
}

t_proc	*proc_lstlast(t_proc *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	proc_lstadd_back(t_proc **lst, t_proc *new)
{
	t_proc	*ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		ptr = proc_lstlast(ptr);
		ptr->next = new;
		new->prev = ptr;
	}
	return ;
}

int	proc_num_count(t_proc *head)
{
	int		num;
	t_proc	*p;

	if (!head)
		return (0);
	num = 0;
	p = head;
	while (p)
	{
		p = p->next;
		num++;
	}
	return (num);
}
