/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:09:17 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 18:09:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

typedef struct s_io
{
	struct s_io	*prev;
	struct s_io	*next;
	char		*word;
	char		*heredoc_file;
	int			fd;
	enum e_kind	kind;
}	t_io;

t_io	*io_lstnew(void);
t_io	*io_lstlast(t_io *lst);
void	io_lstadd_back(t_io **lst, t_io *new);
void	io_lstdelone(t_io *lst, void (*del)(void *));
void	io_lstclear(t_io **lst, void (*del)(void *));

#endif /* IO_H */
