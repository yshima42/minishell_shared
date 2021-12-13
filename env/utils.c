/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 00:09:17 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	xperror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/* void	*xmalloc(size_t size) */
/* { */
/* 	void	*ptr; */

/* 	ptr = malloc(size); */
/* 	if (!ptr) */
/* 	{ */
/* 		perror("malloc"); */
/* 		exit(EXIT_FAILURE); */
/* 	} */
/* 	return (ptr); */
/* } */

char	*ft_trijoin(char const *s1, char const *s2, char const *s3)
{
	return (ft_strjoin(s1, ft_strjoin(s2, s3)));
}

char	**ft_splitfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	while ((u_s1[i] != 0 && u_s2[i] != 0))
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (u_s1[i] - u_s2[i]);
}

char	*mini_getenv(const char *key, t_info *info)
{
	t_dict	*t_env;

	t_env = info->env->next;
	while (t_env != info->env)
	{
		if (ft_strcmp(t_env->key, key) == 0)
			return (t_env->value);
		t_env = t_env->next;
	}
	return (NULL);
}

char	*ft_strajoin(char **str, char *connector)
{
	size_t	i;
	char	*joined_str;
	char	*tmp;

	joined_str = ft_strdup(str[0]);
	i = 1;
	while(str[i])
	{
		tmp = ft_trijoin(joined_str, connector, str[i]);
		free(joined_str);
		joined_str = tmp;
		i++;
	}
	return (joined_str);
}

char	*ft_strtok(char *str, char *sep)
{
	static char	*nexttok;
	char		*next_ptr;
	char		*sep_ptr;

	if (str)
		nexttok = str;
	else
		str = nexttok;
	next_ptr = NULL;
	while (*str)
	{
		if (next_ptr == NULL)
		{
			if (ft_strchr(sep, *str) == NULL)
				next_ptr = str;
		}
		else
		{
			if (ft_strchr(sep, *str) != NULL)
			{
				sep_ptr = str;
				*sep_ptr = '\0';
				nexttok = sep_ptr + 1;
				break;
			}
		}
		str++;
	}
	return (next_ptr);
}
