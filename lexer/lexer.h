/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 17:27:52 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include  <stdio.h>
# include  <stdbool.h>
# include "../libft/mylibft.h"
# include "token.h"
# include "color.h"

# define EQUAL 0

enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE,
};

enum e_token
{
	LEXER,
	SPLIT,
};

t_token	*to_tokenlist(char *line);
t_token	*make_token(char **line, enum e_token when);
size_t	tkn_strlen(const char *start);
size_t	tkn_strlen_word(const char *start, bool (*func)(char));
bool	check_quote_begin(enum e_quote *quote, char c);
bool	check_quote_end(enum e_quote *quote, char c);
bool	is_ifs(char c);
bool	is_operator(char c);
bool	is_2chr_operator(const char *str);
bool	is_quote(char c);
bool	is_end(char c);

#endif /* LEXER_H */
