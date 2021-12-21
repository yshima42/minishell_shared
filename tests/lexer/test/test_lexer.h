/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:10:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/22 00:45:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LEXER_H
# define TEST_LEXER_H

# include "../../../lexer/lexer.h"

void	test_is_ifs(void);
void	test_tknlist(void);
void	test_strndup(void);
void	test_enum_kind(void);
void	test_to_token(char *line, char *tstmsg);
void	test_operator(void);
void	test_quote(void);
void	print_tokens(t_token *head);
void	set_string(char **kstr);

#endif /* TEST_LEXER_H */
