/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:28:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 22:19:42 by yshimazu         ###   ########.fr       */
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
	dict_clear(info->env);
	free(info);
	return (EXIT_SUCCESS);
}
