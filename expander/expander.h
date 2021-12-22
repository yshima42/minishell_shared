/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:31 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/22 11:34:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../lexer/lexer.h"
# include "../env/env.h"
# include "../libft/mylibft.h"

//expand_var.c
char	*expand_var(char *word, t_dict *env);
//expand_var_all.c
t_token	*expand_var_all(t_token *tokens, t_dict *env);
t_token	*remove_empty_token(t_token *tokens);
//utils.c
char	*search_prefix(char *word);
char	*ft_xstrjoin_free(char *str1, char *str2);
bool	is_shellvar_top(int c);
bool	is_shellvar(int c);

#endif
