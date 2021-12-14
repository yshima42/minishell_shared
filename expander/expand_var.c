/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 15:15:16 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//xstrndup, xstrjoin
char	*append_nonvar(char *expanded, char *current, size_t len)
{
	char	*tmp;
	char	*tail;

	tail = ft_xstrndup(current, len);
	tmp = ft_xstrjoin_free(expanded, tail);
	free(tail);
	return (tmp);
}

char	*append_var(char *str, char *value)
{
	return (ft_xstrjoin_free(str, value));
}

char	*fetch_value(char *prefix, size_t key_len, t_info *info)
{
	char	*key;
	char	*value;

	key = ft_xstrndup((prefix + 1), key_len);
	value = mini_getenv(key, info);
	free(key);
	return (value);
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
		key_len = ft_strclen_array((prefix + 1), "\"$");
		value = fetch_value(prefix, key_len, info);
		ret = append_var(ret, value);
		word = prefix + key_len + 1;
	}
	return (ret);
}
