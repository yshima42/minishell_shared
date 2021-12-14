/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:54:49 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:25:43 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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

static t_token	*make_token(char **line)
{
	t_token	*new;
	char	*start;
	char	*word;
	size_t	len;

	start = find_begin(*line);
	if (*start == '\0')
		return (NULL);
	len = tkn_strlen(start);
	word = ft_xstrndup(start, len);
	new = tkn_lstnew(word);
	new->kind = set_kind_info(start);
	*line = start + len;
	return (new);
}

t_token	*to_tokenlist(char *line)
{
	t_token	*head;
	t_token	*tmp;

	head = NULL;
	while (*line != '\0')
	{
		tmp = make_token(&line);
		if (tmp == NULL)
			break;
		tkn_lstadd_back(&head, tmp);
	}
	return (head);
}
