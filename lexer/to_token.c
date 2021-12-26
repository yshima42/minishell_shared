/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:54:49 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/26 22:28:22 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

static char	*find_begin(char *str)
{
	while (is_ifs(*str))
		str++;
	return (str);
}

static enum e_kind	set_kind_info(const char *str)
{
	if (ft_strncmp(str, "<<", 2) == EQUAL)
		return (HEREDOC);
	else if (ft_strncmp(str, ">>", 2) == EQUAL)
		return (APPEND);
	else if (*str == '<')
		return (IN_REDIRECT);
	else if (*str == '>')
		return (OUT_REDIRECT);
	else if (*str == '|')
		return (PIPE);
	else
		return (WORD);
}

t_token	*make_token(char **line, enum e_token when)
{
	t_token	*new;
	char	*start;
	char	*word;
	size_t	len;

	start = find_begin(*line);
	if (!*start)
		return (NULL);
	if (when == LEXER)
		len = tkn_strlen(start);
	else
		len = tkn_strlen_word(start, is_ifs);
	word = ft_xstrndup(start, len);
	new = tkn_lstnew(word);
	if (when == LEXER)
		new->kind = set_kind_info(start);
	else
		new->kind = WORD;
	*line = start + len;
	return (new);
}

t_token	*to_tokenlist(char *line)
{
	t_token	*head;
	t_token	*cur_token;
	char	*cur_line;

	head = NULL;
	cur_line = line;
	while (*cur_line)
	{
		cur_token = make_token(&cur_line, LEXER);
		if (!cur_token)
			break ;
		tkn_lstadd_back(&head, cur_token);
	}
	return (head);
}
