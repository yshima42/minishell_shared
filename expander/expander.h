/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/15 00:18:23 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../lexer/lexer.h"
# include "../minishell.h"

//expand_var.c
char	*append_nonvar(char *expanded, char *current, size_t len);
char	*append_var(char *str, char *value);
char	*fetch_value(char *prefix, size_t key_len, t_info *info);
char	*expand_var(char *word, t_info *info);
//expand_var_all.c
t_token	*expand_var_all(t_token *tokens, t_info *info);
//utils.c
char	*search_prefix(char *word);
char	*ft_xstrjoin_free(char *str1, char *str2);

#endif /* EXPANDER_H */
