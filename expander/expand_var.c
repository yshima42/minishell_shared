/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 17:39:21 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//xstrndup, xstrjoin
char	*append_nonvar(char *str, char *current, size_t len)
{
	char	*tmp;
	char	*tail;

	tail = ft_xstrndup(current, len);
	tmp = ft_xstrjoin_free(str, tail);
	free(tail);
	return (tmp);
}

char	*append_var(char *str, char *value)
{
	char	*tmp;

	tmp = ft_xstrjoin_free(str, value);
	free(value);
	return (tmp);
}

char	*fetch_value(char *prefix, size_t key_len, t_info *info)
{
	char	*key;
	char	*value;

	key = ft_xstrndup((prefix + 1), key_len);
	if (ft_strcmp(key, "?") == EQUAL)
	{
		value = ft_itoa(info->exit_status);
	}
	else
	{
		value = mini_getenv(key, info);
		if (value != NULL)
			value = ft_xstrdup(value);
	}
	free(key);
	return (value);
}

size_t	strlen_key(char *start)
{
	if (*start == '?')
		return (1);
	else
		return (ft_strclen_array(start, "\"\'$"));
}

//xstrjoin
char	*expand_var(char *word, t_info *info)
{
	char	*prefix;
	char	*value;
	char	*ret;
	char	*whead;
	size_t	key_len;

	ret = NULL;
	whead = word;
	while (*word != '\0')
	{
		prefix = search_prefix(word);
		if (prefix == NULL)
			return (ft_xstrjoin_free(ret, word));
		ret = append_nonvar(ret, word, prefix - word);
		key_len = strlen_key(prefix + 1);
		value = fetch_value(prefix, key_len, info);
		ret = append_var(ret, value);
		word = prefix + key_len + 1;
	}
	return (ret);
}
