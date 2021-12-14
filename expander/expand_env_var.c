/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 11:52:36 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*search_prefix(char *word)
{
	enum e_quote	quote;

	quote = NONE;
	while (*word != '\0')
	{
		if (*word == '$' && quote != SINGLE && *(word + 1) != '\0')
			return (word);
		if (quote == NONE)
		{
			check_quote_begin(&quote, *word);
		}
		else
		{
			check_quote_end(&quote, *word);
		}
		word++;
	}
	return (NULL);
}

//xstrndup, xstrjoin
char	*append_nonvar(char *expanded, char *current, size_t len)
{
	char	*tmp;
	char	*tail;

	tail = ft_strndup(current, len);
	if (tail == NULL)
		exit(1);
	tmp = ft_strjoin(expanded, tail);
	if (tmp == NULL)
		exit(1);
	free(tail);
	free(expanded);
	return (tmp);
}

char	*append_var(char *expanded, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(expanded, value);
	if (tmp == NULL)
		exit(1);
	free(expanded);
	return (tmp);
}
char	*fetch_value(char *prefix, size_t key_len, t_info *info)
{
	char	*key;
	char	*value;

	key = ft_strndup((prefix + 1), key_len);
	value = mini_getenv(key, info);
	free(key);
	return (value);
}

//xstrjoin
char	*expand_var(char *word, t_info *info)
{
	char	*prefix;
	char	*value;
	char	*expanded;
	char	*tmp;
	char	*tmp2;
	char	*whead;
	size_t	key_len;

	expanded = NULL;
	tmp = NULL;
	whead = word;
	prefix = search_prefix(word);
	if (prefix == NULL)
		return (word);
	while (*word != '\0')
	{
		prefix = search_prefix(word);
		if (prefix == NULL)
		{
			tmp2 = ft_strjoin(tmp, word);
			free(tmp);
			free(whead);
			return (tmp2);
		}
		tmp = append_nonvar(tmp, word, prefix - word);
		printf("[tmp]%s\n", tmp);
		key_len = ft_strclen_array((prefix + 1), "\"$");
		value = fetch_value(prefix, key_len, info);
		tmp = append_var(tmp, value);
		printf("[tmp2]%s\n", tmp);
		word = prefix + key_len + 1;
	}
	free(whead);
	return (tmp);
}

t_token	*expand_var_all(t_token *tokens, t_info *info)
{
	t_token	*head;

	head = tokens;
	while (tokens != NULL)
	{
		tokens->word = expand_var(tokens->word, info);
		tokens = tokens->next;
	}
	return (head);
}

