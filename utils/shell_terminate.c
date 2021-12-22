/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_terminate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:06:25 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/21 19:07:46 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	shell_terminate(t_info *info)
{
	dict_clear(info->env);
	dict_clear(info->pwd);
	free(info);
	rl_clear_history();
}
