/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:27 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/04 17:38:56 by hyoshie          ###   ########.fr       */
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
	new->heredoc_file = NULL;
	new->kind = WORD;
	new->is_empty = false;
	return (new);
}

t_token	*tkn_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
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

void	tkn_lstlink(t_token *before, t_token *after)
{
	if (before)
		before->next = after;
	if (after)
		after->prev = before;
	return ;
}

t_token	*tkn_lstdup(t_token *old)
{
	t_token	*new;

	new = (t_token *)xmalloc(sizeof(t_token));
	new->prev = NULL;
	new->next = NULL;
	new->word = ft_xstrdup(old->word);
	if (old->heredoc_file)
		new->heredoc_file = ft_xstrdup(old->heredoc_file);
	else
		new->heredoc_file = NULL;
	new->kind = old->kind;
	new->is_empty = old->is_empty;
	return (new);
}
