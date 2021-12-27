/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:31:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*append_nonvar(char *str, char *current, size_t len)
{
	char	*ret;
	char	*tail;

	tail = ft_xstrndup(current, len);
	ret = ft_xstrjoin_free(str, tail);
	free(tail);
	return (ret);
}

static char	*append_var(char *str, char *prefix, size_t var_len, t_dict *env)
{
	char	*var;
	char	*value;
	char	*ret;

	var = ft_xstrndup((prefix + 1), var_len);
	if (ft_strcmp(var, "?") == EQUAL)
	{
		value = ft_itoa(g_exit_status);
	}
	else
	{
		value = dict_get_value(var, env);
		if (value)
			value = ft_xstrdup(value);
	}
	ret = ft_xstrjoin_free(str, value);
	free(var);
	free(value);
	return (ret);
}

static size_t	strlen_var(char *var_begin)
{
	size_t	len;

	len = 1;
	if (*var_begin == '?')
		return (len);
	else
	{
		if (!is_shellvar_top(*var_begin))
			return (len);
		var_begin++;
		while (*var_begin)
		{
			if (!is_shellvar(*var_begin))
				return (len);
			len++;
			var_begin++;
		}
		return (len);
	}
}

char	*replace_var_in_str(char *word, t_dict *env)
{
	char			*prefix;
	char			*ret;
	size_t			var_len;
	enum e_quote	quote;

	ret = NULL;
	quote = NONE;
	while (*word)
	{
		prefix = search_prefix(word, &quote);
		if (!prefix)
			return (ft_xstrjoin_free(ret, word));
		var_len = strlen_var(prefix + 1);
		ret = append_nonvar(ret, word, prefix - word);
		ret = append_var(ret, prefix, var_len, env);
		word = prefix + var_len + 1;
	}
	return (ret);
}
