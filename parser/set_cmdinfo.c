/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmdinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:07:12 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 11:35:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_word(t_token *tokens)
{
	size_t	cmd_num;

	cmd_num = 0;
	while (tokens && !is_pipe(tokens->kind))
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
	t_token	*current;
	size_t	idx;

	current = *tokens;
	cmd_num = count_word(current);
	cmd = (char **)xmalloc(sizeof(char *) * (cmd_num + 1));
	idx = 0;
	while (current && !is_pipe(current->kind))
	{
		if (is_cmd(current))
			cmd[idx++] = ft_xstrdup(current->word);
		current = current->next;
	}
	cmd[idx] = NULL;
	if (current && is_pipe(current->kind))
		current = current->next;
	*tokens = current;
	return (cmd);
}
