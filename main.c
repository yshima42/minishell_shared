/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:25:58 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_info	*info;
	//arg_check
	//bash initiate
	info = shell_init();
	loop_shell(info);
	dict_clear(info->env);
	return (EXIT_SUCCESS);
}
