/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:41:47 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 00:12:25 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/mylibft.h"
# include "../env/env.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

int	g_exit_status;

typedef enum e_stdfd
{
	SAVED_IN,
	SAVED_OUT,
	SAVED_ERR,
	STDFD_NUM
}	t_stdfd;

typedef struct s_info
{
	t_dict	*env;
	t_dict	*pwd;
	int		stdfd[STDFD_NUM];
}	t_info;

//utils/utils.c
void	save_stdfd(t_info *info);
char	**ft_splitfree(char **tab);
char	*mini_getenv(const char *key, t_info *info);
//utils/error.c
void	ms_puterr_2arg(char *str1, char *str2);
void	xperror_2(char *str1, char *str2);
void	perror_2(char *str1, char *str2);
//utils/shell_init.c
t_info	*shell_init(void);
void	shell_terminate(t_info *info);

#endif
