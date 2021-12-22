/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:41:47 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/21 19:08:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/mylibft.h"
# include "../env/env.h"
# include <readline/readline.h>
# include <readline/history.h>

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

void	save_stdfd(t_info *info);
char	**ft_splitfree(char **tab);
char	*mini_getenv(const char *key, t_info *info);
t_info	*shell_init(void);
void	shell_terminate(t_info *info);

#endif
