/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:32:50 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 17:10:01 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"
# include "../expander/expander.h"

# define DEFAULT -1
# define EMPTY_LINE 0
# define HEREDOC_EXIT 1
# define ARG_TOOLONG 126 
# define SYNTAX_ERR 258 
# define MS_ARG_MAX 26057

//2>?
typedef struct s_io
{
	struct s_io	*prev;
	struct s_io	*next;
	char		*word;
	char		*heredoc_file;
	int			fd;
	enum e_kind	kind;
}	t_io;

typedef struct s_proc
{
	struct s_proc	*prev;
	struct s_proc	*next;
	char			**cmd;
	t_io			*io_info;
	size_t			id;
}	t_proc;

int		parse_line(t_proc **proclist, char *line, t_dict *env);
t_proc	*to_proclist(t_token *tokens);
bool	validate_syntax(t_token *tokens);
bool	validate_arg_num(t_proc *procs);
size_t	count_quote(char *word);
t_token	*remove_quote(t_token *tokens);
char	*remove_quote_in_token(char *word);
size_t	count_process(t_token *tokens);
t_proc	*init_procinfo(size_t proc_num);
t_proc	*set_procinfo(t_proc *procs, t_token *tokens, size_t proc_num);
t_io	*set_ioinfo(t_token *tokens);
char	**set_cmdinfo(t_token **tokens);
bool	is_io_operator(enum e_kind kind);
bool	is_pipe(enum e_kind kind);
bool	is_op_kind(enum e_kind kind);
bool	is_cmd(t_token *token);
t_token	*split_expanded_word(t_token *old);
//list
t_proc	*proc_lstnew(void);
t_proc	*proc_lstlast(t_proc *lst);
int		proc_num_count(t_proc *head);
void	proc_lstadd_back(t_proc **lst, t_proc *new);
void	proc_lstdelone(t_proc *lst);
void	proc_lstclear(t_proc **lst);
t_io	*io_lstnew(void);
t_io	*io_lstlast(t_io *lst);
void	io_lstadd_back(t_io **lst, t_io *new);
void	io_lstdelone(t_io *lst, void (*del)(void *));
void	io_lstclear(t_io **lst, void(*del)(void *));

#endif /* PARSER_H */
