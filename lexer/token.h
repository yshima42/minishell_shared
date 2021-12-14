/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:35:02 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:52:11 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*word;
	enum e_kind		kind;
	enum e_quote	quote;
}	t_token;

t_token	*tkn_lstnew(char *str);
t_token	*tkn_lstlast(t_token *lst);
void	tkn_lstadd_back(t_token **lst, t_token *new);
void	tkn_lstdelone(t_token *lst, void (*del)(void *));
void	tkn_lstclear(t_token **lst, void(*del)(void *));

#endif /* TOKEN_H */
