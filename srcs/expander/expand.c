/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:14:28 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/27 18:32:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_token	*expand(t_token *tokens, t_dict *env)
{
	t_token	*new;

	new = replace_vars(tokens, env);
	new = split_with_value_ifs(new);
	new = remove_quoting(new);
	if (!new)
		g_exit_status = 0;
	return (new);
}
