/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:57:02 by hyoshie          ###   ########.fr       */
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

t_token	*to_tokenlist(char *line);
size_t	tkn_strlen(const char *start);
bool	check_quote_begin(enum e_quote *quote, char c);
bool	check_quote_end(enum e_quote *quote, char c);
bool	is_ifs(char c);
bool	is_operator(char c);
bool	is_2chr_operator(const char *str);
bool	is_quote(char c);
bool	is_end(char c);

#endif /* LEXER_H */
