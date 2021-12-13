/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/13 00:10:55 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../lexer/lexer.h"
# include "../env/minishell.h"

//expand_env_var.c
char	*search_prefix(char *word);
char	*append_nonvar(char *expanded, char *current, size_t len);
char	*append_var(char *expanded, char *value);
char	*fetch_value(char *prefix, size_t key_len, t_info *info);
char	*expand_var(char *word, t_info *info);
t_token	*expand_var_all(t_token *tokens, t_info *info);

#endif /* EXPANDER_H */
