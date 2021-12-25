/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:22:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/25 20:06:44 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*search_connector(char *line)
{
	char	*join_ptr;
	char	*assign_ptr;

	join_ptr = ft_strnstr(line, "+=", ft_strlen(line));
	assign_ptr = ft_strchr(line, '=');
	if (join_ptr && join_ptr != line)
		return ("+=");
	if (assign_ptr && assign_ptr != line)
		return ("=");
	return (NULL);
}

static void	update_env(char *key, char *value, char *connector, t_dict *env)
{
	t_dict	*item;

	item = dict_search_item(key, env);
	if (connector && ft_strcmp(connector, "+=") == 0)
	{
		if (item)
			item->value = ft_xstrjoin_free(item->value, value);
		else
			dict_addback(env, xdict_new(key, value));
	}
	else
	{
		dict_update_value(key, value, env);
	}
	return ;
}

static void	export_item(char *arg, t_dict *env)
{
	char			*key;
	char			*value;
	char			*connector;

	connector = search_connector(arg);
	if (!connector)
	{
		key = ft_xstrdup(arg);
		value = NULL;
	}
	else
	{
		key = dict_substr_key(arg, connector);
		value = dict_substr_value(arg, connector);
	}
	update_env(key, value, connector, env);
}

void	export_loop(char **args, t_dict *env)
{
	while (*args)
	{
		if (validate_identifier(*args))
		{
			export_item(*args, env);
		}
		else
		{
			puterr_not_validate(*args, "export");
			g_exit_status = 1;
		}
		args++;
	}
}

int	exec_export(char **cmd, t_dict *env)
{
	g_exit_status = 0;
	cmd++;
	if (!*cmd)
	{
		show_environment(env, EXPORT);
	}
	else
	{
		export_loop(cmd, env);
	}
	return (CONTINUE);
}
// void	ms_puterr(char *str1, char *str2, char *msg)
// {
// 	ft_putstr_fd("minishell: ", STDERR_FILENO);
// 	if (str1 != NULL)
// 	{
// 		ft_putstr_fd(str1, STDERR_FILENO);
// 		ft_putstr_fd(": ", STDERR_FILENO);
// 	}
// 	if (str2 != NULL)
// 	{
// 		ft_putstr_fd(str2, STDERR_FILENO);
// 		ft_putstr_fd(": ", STDERR_FILENO);
// 	}
// 	ft_putendl_fd(msg, STDERR_FILENO);
// 	return ;
// }
