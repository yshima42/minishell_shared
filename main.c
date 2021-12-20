/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/20 16:16:45 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//arg_check
//bash initiate
int	main(void)
{
	t_info	*info;
	int		ms_exit_status;

	info = shell_init();
	ms_exit_status = loop_shell(info);
	dict_clear(info->env);
	dict_clear(info->pwd);
	free(info);
	return (ms_exit_status);
}

/* void    detect_leak(void)__attribute__((destructor));

void    detect_leak(void)
{
     system("leaks -q minishell");
}
 */
