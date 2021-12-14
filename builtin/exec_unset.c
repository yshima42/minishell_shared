/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:18:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 11:49:18 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_unset(char **args, t_info *info)
{	
	size_t	i;

	if (!args[1])
		return (1);
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
			printf("'%s': not a valid identifier\n", args[i]);//need to fix how to print error
		i++;
	}
	del_envs(&args[1], info);
	return (0); 
}