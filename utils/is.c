/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:26:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 17:07:52 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_single_proc(t_proc *proc)
{
	return (!proc->next);
}

bool	is_redirect(t_proc *proc)
{
	return (proc->io_info);
}

bool	is_first_proc(t_proc *proc)
{
	return (proc->id == 0);
}

bool	is_last_proc(t_proc *proc)
{
	return (!proc->next);
}

bool	is_no_cmd(t_proc *proc)
{
	return (!proc->cmd[0]);	
}
