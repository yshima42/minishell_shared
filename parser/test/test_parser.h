/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:53:48 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 14:26:54 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PARSER_H
# define TEST_PARSER_H

# include "../parser.h"
# include "../../lexer/test/test_lexer.h"

//test_count.c
void	test_start(void);
void	test_count_process(char *line, char *tstmsg);
void	test_count_processes(void);
//test_count_quote.c
void	test_count_quote(char *line, char *tstmsg);
void	test_count_quotes(void);
//test_init.c
void	test_init_procinfo(char *line, char *tstmsg);
void	test_init_procinfos(void);
//test_rm_quote.c
void	test_rm_quote_word(char *word, char *tstmsg);
void	test_rm_quote_words(void);
void	test_rm_quote(char *line, char *tstmsg);
void	test_rm_quotes(void);
//test_set.c
void	test_set_procinfo(char *line, char *tstmsg);
void	test_set_procinfos(void);
//test_validate.c
void	test_validate(char *line, char *tstmsg);
void	test_validates(void);
//utils_test.c
void	print_vector(char **vector);
void	print_iolist(t_io *io_info);
void	print_procinfo(t_proc *proc, int ex_status);
void	print_proclist(t_proc *head, int ex_status);
//parser/test/test_parse_line.c
void	test_parse_line(char *line, char *tstmsg);
void	test_parse_lines(void);

#endif /* TEST_PARSER_H */
