/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:15:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/17 10:26:36 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	has_no_arg(char **cmd)
{
	if (cmd == NULL)
		return (false);
	if (cmd[1] == NULL)
		return (true);
	else
		return (false);
}

bool	has_one_arg(char **cmd)
{
	if (cmd == NULL)
		return (false);
	if (cmd[1] == NULL)
		return (false);
	if (cmd[2] == NULL)
		return (true);
	else
		return (false);
}
