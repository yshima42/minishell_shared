/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/21 19:11:38 by hyoshie          ###   ########.fr       */
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
	return (g_exit_status);
}
