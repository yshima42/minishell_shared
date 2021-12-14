/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:56:57 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 17:13:53 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/mylibft.h"
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

/* # define END			"\033[0m" */
/* # define BLACK			"\033[30m" */
/* # define RED			"\033[31m" */
/* # define GREEN			"\033[32m" */
/* # define YELLOW			"\033[33m" */
/* # define BLUE			"\033[34m" */
/* # define MAGENTA		"\033[35m" */
/* # define CYAN			"\033[36m" */

# define EQUAL 0

# define MAX_PROC 709

typedef struct	s_info
{
	t_dict	*env;
	int		exit_status;
}	t_info;


//要検討
#define pathname_size 512

//utils.c
char	*mini_getenv(const char *key, t_info *info);

//test.c 後で消す
void	test_args_check(char **args);
void	print_all_env(t_dict *env);


//shell_init.c
t_info	*shell_init(void);

//env_utils.c
void	add_envs(char **envs, t_info *info);
void	del_envs(char **envs, t_info *info);

//dict_utils.c
bool	ft_dictdelone(t_dict *elem);
void	ft_dicclear(t_dict **dic, void (*del)(void *));
bool	ft_dictadd_back(t_dict *head, t_dict *new);
t_dict	*ft_dictnew(char *key, char *value);
void	ft_dictdel_back(t_dict **dict, void (*del)(void*));
void	ft_dict_clear(t_dict *head);

#endif
