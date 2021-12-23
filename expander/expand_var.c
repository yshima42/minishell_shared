/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/23 22:53:21 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*append_nonvar(char *str, char *current, size_t len)
{
	char	*tmp;
	char	*tail;

	tail = ft_xstrndup(current, len);
	tmp = ft_xstrjoin_free(str, tail);
	free(tail);
	return (tmp);
}

static char	*append_var(char *str, char *prefix, size_t key_len, t_dict *env)
{
	char	*key;
	char	*value;
	char	*ret;

	key = ft_xstrndup((prefix + 1), key_len);
	if (ft_strcmp(key, "?") == EQUAL)
	{
		value = ft_itoa(g_exit_status);
	}
	else
	{
		value = dict_get_value(key, env);
		if (value)
			value = ft_xstrdup(value);
	}
	ret = ft_xstrjoin_free(str, value);
	free(key);
	free(value);
	return (ret);
}

static size_t	strlen_key(char *key_begin)
{
	size_t	len;

	len = 1;
	if (*key_begin == '?')
		return (len);
	else
	{
		if (!is_shellvar_top(*key_begin))
			return (len);
		key_begin++;
		while (*key_begin)
		{
			if (!is_shellvar(*key_begin))
				return (len);
			len++;
			key_begin++;
		}
		return (len);
	}
}

char	*expand_var(char *word, t_dict *env, bool *is_empty)
{
	char	*prefix;
	char	*ret;
	char	*top;
	size_t	key_len;

	top = word;
	ret = NULL;
	while (*word)
	{
		prefix = search_prefix(word);
		if (!prefix)
			return (ft_xstrjoin_free(ret, word));
		key_len = strlen_key(prefix + 1);
		ret = append_nonvar(ret, word, prefix - word);
		ret = append_var(ret, prefix, key_len, env);
		word = prefix + key_len + 1;
	}
	if (!ret[0])
	{
		free(ret);
		ret = ft_xstrdup(top);
		*is_empty = true;
	}
	return (ret);
}
