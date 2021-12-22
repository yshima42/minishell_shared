/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:22:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 22:59:37 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static enum e_symbol	search_symbol(char *arg)
{
	char	*join_ptr;
	char	*assign_ptr;

	join_ptr = ft_strnstr(arg, "+=", ft_strlen(arg));
	assign_ptr = ft_strchr(arg, '=');
	if (join_ptr != NULL && join_ptr != arg)
		return (JOIN);
	if (assign_ptr != NULL && assign_ptr != arg)
		return (ASSIGN);
	return (NO_SYMBOL);
}

static void	get_key_and_value(char *key_begin, enum e_symbol symbol, \
							char **key, char **value)
{
	char	*key_end;
	char	*value_begin;
	size_t	key_len;

	if (symbol == JOIN)
	{
		key_end = ft_strnstr(key_begin, "+=", ft_strlen(key_begin));
		value_begin = key_end + 2;
	}
	else
	{
		key_end = ft_strchr(key_begin, '=');
		value_begin = key_end + 1;
	}
	key_len = key_end - key_begin;
	if (key_len == 0)
		*key = NULL;
	else
		*key = ft_xstrndup(key_begin, key_len);
	if (*value_begin == '\0')
		*value = NULL;
	else
		*value = ft_xstrdup(value_begin);
	return ;
}

void	update_env(char *key, char *value, enum e_symbol symbol, \
						t_dict *env)
{
	t_dict	*item;

	item = dict_search_item(key, env);
	if (symbol == JOIN)
	{
		if (item != NULL)
		{
			if (ft_strcmp(item->key, "_") != 0)
				item->value = ft_xstrjoin_free(item->value, value);
		}
		else
			dict_addback(env, xdict_new(key, value));
	}
	else
	{
		if (item != NULL)
		{
			free(key);
			free(item->value);
			item->value = value;
		}
		else
			dict_addback(env, xdict_new(key, value));
	}
	return ;
}

static void	export_one_data(char *arg, t_dict *env)
{
	enum e_symbol	symbol;
	char			*key;
	char			*value;

	symbol = search_symbol(arg);
	if (symbol == NO_SYMBOL)
	{
		if (!validate_identifier(arg))
			puterr_not_validate(arg, "export");
	}
	else
	{
		get_key_and_value(arg, symbol, &key, &value);
		if (ft_strcmp(key, "_") == 0)
			multi_free(key, value, NULL, NULL);
		else if (!validate_identifier(key))
		{
			puterr_not_validate(arg, "export");
			multi_free(key, value, NULL, NULL);
		}
		else
		{
			update_env(key, value, symbol, env);
		}
	}
}

int	exec_export(char **cmd, t_dict *env)
{
	g_exit_status = 0;
	cmd++;
	if (*cmd == NULL)
		show_environment(env, EXPORT);
	else
	{
		while (*cmd != NULL)
		{
			export_one_data(*cmd, env);
			cmd++;
		}
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
