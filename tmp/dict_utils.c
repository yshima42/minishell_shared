/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:38:26 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/13 20:28:11 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dict_clear(t_dict *head)
{
	t_dict	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free(p->prev->key);
		free(p->prev->value);
		free (p->prev);
	}
	free (head);
}

size_t	dict_size(t_dict *head)
{
	size_t	size;
	t_dict	*p;

	if (!head)
		return (0);
	size = 0;
	p = head->next;
	while (p != head)
	{
		p = p->next;
		size++;
	}
	return (size);
}

bool	dict_delone(t_dict *elem)
{
	t_dict	*front;
	t_dict	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem->key);
	free(elem->value);
	free(elem);
	return (true);
}

bool	dict_addback(t_dict *head, t_dict *new)
{
	if (!head || !new)
		return (false);
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (true);
}

t_dict	*dict_new(char *key, char *value)
{
	t_dict	*elem;

	elem = (t_dict *)malloc(sizeof(t_dict));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->value = value;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
