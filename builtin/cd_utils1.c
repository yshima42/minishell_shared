/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:17:47 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/24 00:04:46 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*set_cd_dest(char **args, t_info *info)
{
	char	*home_env;
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
	{
		if (!(dict_search_item("HOME", info->env)))
		{
			print_error("HOME not set", "cd");
			return (NULL);
		}
		home_env = dict_get_value("HOME", info->env);
		if (!home_env)
			return (NULL);
		return (ft_xstrdup(home_env));
	}
	return (ft_xstrdup(args[1]));
}

void	array_to_clst(t_clst *clst_head, char **array)
{
	size_t	i;

	i = -1;
	while (array[++i])
		clst_addback(clst_head, clst_new(ft_strdup(array[i])));
	ft_splitfree(array);
}

t_clst	*path_to_clst(char *current_path, char *operand)
{
	char	*path;
	t_clst	*path_clst;
	char	**path_array;

	if (is_from_slash(operand))
		path = ft_xstrdup(operand);
	else
		path = ft_xtrijoin(current_path, "/", operand);
	path_array = ft_xsplit(path, '/');
	free(path);
	path_clst = clst_new("");
	array_to_clst(path_clst, path_array);
	return (path_clst);
}

void	del_before_dots(t_clst *path_clst)
{
	t_clst	*p;

	p = path_clst->next;
	while (p != path_clst)
	{
		if (ft_strcmp(p->content, "..") == 0)
		{
			p = p->next;
			clst_delone(p->prev);
			if (p->prev != path_clst)
				clst_delone(p->prev);
			continue ;
		}
		p = p->next;
	}
}

char	*clst_to_line(t_clst *clst)
{
	t_clst	*p;
	char	*line;
	char	*tmp;

	p = clst->next;
	line = ft_xstrjoin("/", p->content);
	p = p->next;
	while (p != clst)
	{
		tmp = ft_xtrijoin(line, "/", p->content);
		free(line);
		line = tmp;
		p = p->next;
	}
	return (line);
}
