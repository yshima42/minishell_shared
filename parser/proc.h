/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:10:49 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 18:11:34 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC_H
# define PROC_H

# include "io.h"

typedef struct s_proc
{
	struct s_proc	*prev;
	struct s_proc	*next;
	char			**cmd;
	t_io			*io_info;
	size_t			id;
}	t_proc;

t_proc	*proc_lstnew(void);
t_proc	*proc_lstlast(t_proc *lst);
int		proc_num_count(t_proc *head);
void	proc_lstadd_back(t_proc **lst, t_proc *new);
void	proc_lstdelone(t_proc *lst);
void	proc_lstclear(t_proc **lst);

#endif /* PROC_H */
