/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:27 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:55:51 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*tkn_lstnew(char *str)
{
	t_token	*new;

	new = (t_token *)xmalloc(sizeof(t_token));
	new->prev = NULL;
	new->next = NULL;
	new->word = str;
	new->kind = WORD;
	return (new);
}

t_token	*tkn_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	tkn_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		ptr = tkn_lstlast(ptr);
		ptr->next = new;
		new->prev = ptr;
	}
	return ;
}
