/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_ctype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/08 11:27:18 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_ifs(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (true);
	else
		return (false);
}

bool	is_operator(char c)
{
	if (c == '|' || \
		c == '>' || c == '<')
		return (true);
	else
		return (false);
}

bool	is_2chr_operator(const char *str)
{
	if (ft_strncmp(str, ">>", 2) == EQUAL || ft_strncmp(str, "<<", 2) == EQUAL)
		return (true);
	else
		return (false);
}

bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	else
		return (false);
}

bool	is_end(char c)
{
	if (is_ifs(c) || is_operator(c))
		return (true);
	else
		return (false);
}
