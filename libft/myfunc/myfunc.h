/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:05 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/10 17:43:05 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFUNC_H
# define MYFUNC_H

# include <stdio.h>
# include <stdbool.h>
# include "../subject/libft.h"
# include "../gnl/get_next_line.h"
# include "color.h"
# include "dict.h"

char	*ft_ulongtoa_base(unsigned long nbr, char *base);
size_t	ft_strclen(const char *str, int c);
size_t	ft_strclen_array(const char *str, char *sep);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);
int		ft_v_strchr(const char *str, int c);
size_t	ft_lstsize_sizet(t_list *lst);
char	**convert_file_to_vector(int fd);
void	free_vector(char **vector);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_trijoin(char const *s1, char const *s2, char const *s3);

//yshima
char	*ft_strajoin(char **str, char *connector);
int		ft_strcmp(const char *s1, const char *s2);

//xfunction
void	*xmalloc(size_t size);
char	*ft_xstrdup(const char *s1);
void	xdup2(int fd1, int fd2);
pid_t	xfork(void);
void	xperror(char *s);
void	xpipe(int *fd);

#endif
