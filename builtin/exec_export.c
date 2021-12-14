/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:22:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 11:49:11 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_export(char **args, t_info *info)
{
	//=だけの時などのエラー処理が必要、lexerとかで判断するか検討
	//when only "=" comes, what we do?? consider to judge in lexer or not.
	add_envs(&args[1], info);
	return (0);
}
