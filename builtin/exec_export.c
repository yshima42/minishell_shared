/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:22:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/17 11:26:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//=だけの時などのエラー処理が必要、lexerとかで判断するか検討
	//when only "=" comes, what we do?? consider to judge in lexer or not.
int	exec_export(char **args, t_info *info)
{
	(void)args;
	(void)info;
	//add_envs(&args[1], info);
	g_exit_status = 0;
	return (CONTINUE);
}
