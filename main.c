/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/21 19:08:33 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//arg_check
//bash initiate
int	main(void)
{
	t_info	*info;

	info = shell_init();
	loop_shell(info);
	shell_terminate(info);
	// dict_clear(info->env);
	// dict_clear(info->pwd);
	// free(info);
	// rl_clear_history();
	return (g_exit_status);
}
