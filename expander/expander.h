/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 14:36:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../lexer/lexer.h"
# include "../env/env.h"
# include "../libft/mylibft.h"

//expander/expand.c
t_token	*expand(t_token *tokens, t_dict *env);
//expander/remove_quote.c
char	*remove_quoting_in_str(char *word);
t_token	*remove_quoting(t_token *tokens);
//expander/replace_var_in_str.c
char	*replace_var_in_str(char *word, t_dict *env);
//expander/replace_vars.c
t_token	*replace_vars(t_token *tokens, t_dict *env);
//expander/split_with_value_ifs.c
t_token	*split_with_value_ifs(t_token *old);
//expander/utils.c
char	*search_prefix(char *word, enum e_quote *quote);
char	*ft_xstrjoin_free(char *str1, char *str2);
bool	is_shellvar_top(int c);
bool	is_shellvar(int c);

#endif
