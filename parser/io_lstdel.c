/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:49:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/19 01:50:59 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//Need connect prev and next?
void	io_lstdelone(t_io *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->word);
	free(lst->heredoc_file);
	free(lst);
	return ;
}

void	io_lstclear(t_io **lst, void(*del)(void *))
{
	t_io	*tmp;
	t_io	*current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		io_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
	return ;
}
