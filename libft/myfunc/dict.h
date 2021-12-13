/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:59 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/10 17:32:38 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdbool.h>

typedef struct s_dict
{
	struct s_dict	*prev;
	char			*key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

bool	dict_addback(t_dict *head, t_dict *new);
void	dict_clear(t_dict *head);
bool	dict_delone(t_dict *elem);
t_dict	*dict_new(char *key, char *value);
size_t	dict_size(t_dict *head);
char	**dict_to_array(t_dict *dict_head);

#endif
