/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:56:32 by yshimazu          #+#    #+#             */
/*   Updated: 2022/01/05 12:41:17 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../parser/parser.h"
# include "../signal/ms_signal.h"
# include <fcntl.h>

int	heredoc_handler(t_token *tokens, t_dict *env);
int	store_heredoc(t_token *tokens, t_dict *env, int heredoc_fd);

#endif
