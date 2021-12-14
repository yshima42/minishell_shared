/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expander.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:41:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 17:42:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_EXPANDER_H
# define TEST_EXPANDER_H

# include "../expander.h"
# include "../../lexer/test/test_lexer.h"

//expander/test/test_append_nonvar.c
void	test_append_nonvar(char *str, char *tail, size_t len, char *tstmsg);
void	test_append_nonvars(void);
//expander/test/test_expand_var.c
void	test_expand_var(char *word, char *tstmsg);
void	test_expand_vars(void);
void	test_expand_exit_status(void);
//expander/test/test_expand_var_all.c
void	test_expand_var_all(char *line, char *tstmsg);
void	test_expand_var_alls(void);
//expander/test/test_search_prefix.c
void	test_search_prefix(char *word, char *tstmsg);
void	test_search_prefixs(void);
//expander/test/test_strclen_array.c
void	test_strclen_array(char *str, char *sep, char *tstmsg);
void	test_strclen_arrays(void);

#endif /* TEST_EXPANDER_H */
