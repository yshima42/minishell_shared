/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:27 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 01:35:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

//Need connect prev and next?
void	tkn_lstdelone(t_token *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->word);
		del(lst->heredoc_file);
	}
	free(lst);
	return ;
}

void	tkn_lstclear(t_token **lst, void (*del)(void *))
{
	t_token	*current;
	t_token	*tmp;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		tkn_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
	return ;
}
