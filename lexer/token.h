/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:35:02 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/04 17:23:29 by hyoshie          ###   ########.fr       */
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

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*word;
	char			*heredoc_file;
	enum e_kind		kind;
	bool			is_empty;
}	t_token;

t_token	*tkn_lstnew(char *str);
t_token	*tkn_lstlast(t_token *lst);
void	tkn_lstadd_back(t_token **lst, t_token *new);
void	tkn_lstlink(t_token *before, t_token *after);
t_token	*tkn_lstdup(t_token *old);
void	tkn_lstdelone(t_token *lst, void (*del)(void *));
void	tkn_lstclear(t_token **lst, void (*del)(void *));

#endif
