/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:54:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:30:40 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*store_nonexist_var(char *ret, char *original, bool *is_empty)
{
	*is_empty = true;
	free(ret);
	ret = ft_xstrdup(original);
	return (ret);
}

static char	*replace_var(char *word, t_dict *env, bool *is_empty)
{
	char	*ret;
	char	*original;

	original = word;
	ret = replace_var_in_str(word, env);
	if (!ret[0])
		ret = store_nonexist_var(ret, original, is_empty);
	return (ret);
}

t_token	*replace_vars(t_token *tokens, t_dict *env)
{
	t_token	*head;
	char	*tmp;

	head = tokens;
	while (tokens)
	{
		tmp = tokens->word;
		tokens->word = replace_var(tokens->word, env, &tokens->is_empty);
		free(tmp);
		tokens = tokens->next;
	}
	return (head);
}
