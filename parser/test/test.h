/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:51 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/08 16:51:36 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../parser.h"

void	print_proclist(t_proc *head, int ex_status);
void	test_start(void);
void	test_count_process(char *line, char *tstmsg);
void	test_count_processes(void);
void	test_validate(char *line, char *tstmsg);
void	test_validates(void);
void	test_init_procinfo(char *line, char *tstmsg);
void	test_init_procinfos(void);
void	test_set_procinfos(void);
void	test_rm_quote(char *line, char *tstmsg);
void	test_rm_quotes(void);
void	test_count_quote(char *line, char *tstmsg);
void	test_count_quotes(void);
void	test_rm_quote_word(char *word, char *tstmsg);
void	test_rm_quote_words(void);

#endif /* TEST_H */
