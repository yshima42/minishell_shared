/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:28:15 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include  <stdio.h>
# include  <stdbool.h>
# include "../libft/mylibft.h"
# include "color.h"

# define EQUAL 0

//type is better?
enum e_kind
{
	WORD,
	HEREDOC,
	APPEND,
	IN_REDIRECT,
	OUT_REDIRECT,
	PIPE,
	LAST,
};

enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE,
};

//when token to node, nyokota use funcptr
typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*word;
	enum e_kind		kind;
	enum e_quote	quote;
}	t_token;

t_token	*to_tokenlist(char *line);
size_t	tkn_strlen(const char *start);
bool	check_quote_begin(enum e_quote *quote, char c);
bool	check_quote_end(enum e_quote *quote, char c);
bool	is_ifs(char c);
bool	is_operator(char c);
bool	is_2chr_operator(const char *str);
bool	is_quote(char c);
bool	is_end(char c);
t_token	*tkn_lstnew(char *str);
t_token	*tkn_lstlast(t_token *lst);
void	tkn_lstadd_back(t_token **lst, t_token *new);
void	tkn_lstdelone(t_token *lst, void (*del)(void *));
void	tkn_lstclear(t_token	**lst, void(*del)(void *));

#endif /* LEXER_H */
