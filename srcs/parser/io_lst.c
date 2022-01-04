/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:09:19 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/23 16:16:56 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io	*io_lstnew(void)
{
	t_io	*new;

	new = (t_io *)xmalloc(sizeof(t_io));
	new->prev = NULL;
	new->next = NULL;
	new->word = NULL;
	new->heredoc_file = NULL;
	new->kind = LAST;
	new->is_empty = false;
	return (new);
}

t_io	*io_lstlast(t_io *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	io_lstadd_back(t_io **lst, t_io *new)
{
	t_io	*ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		ptr = io_lstlast(ptr);
		ptr->next = new;
		new->prev = ptr;
	}
	return ;
}
