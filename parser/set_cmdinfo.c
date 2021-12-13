/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmdinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:07:12 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/07 14:45:06 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_word(t_token *tokens)
{
	size_t	cmd_num;

	cmd_num = 0;
	while (tokens != NULL && !is_pipe(tokens->kind))
	{
		if (is_cmd(tokens))
			cmd_num++;
		tokens = tokens->next;
	}
	return (cmd_num);
}

char	**set_cmdinfo(t_token **tokens)
{
	char	**cmd;
	size_t	cmd_num;
	t_token	*tmp;
	size_t	idx;

	if (tokens == NULL)
		return (NULL);
	tmp = *tokens;
	cmd_num = count_word(tmp);
	cmd = (char **)xmalloc(sizeof(char *) * (cmd_num + 1));
	idx = 0;
	while (tmp != NULL && !is_pipe(tmp->kind))
	{
		if (is_cmd(tmp))
			cmd[idx++] = ft_xstrdup(tmp->word);
		tmp = tmp->next;
	}
	cmd[idx] = NULL;
	if (tmp != NULL && is_pipe(tmp->kind))
		tmp = tmp->next;
	*tokens = tmp;
	return (cmd);
}
