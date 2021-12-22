/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:27 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 14:58:41 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

//Need connect prev and next?
void	tkn_lstdelone(t_token *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->word);
	free(lst);
	return ;
}

void	tkn_lstclear(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;
	t_token	*current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		tkn_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
	return ;
}
