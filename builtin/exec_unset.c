/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:18:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/15 17:38:32 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_unset(char **args, t_info *info)
{	
	(void)args;
	(void)info;
	/* size_t	i;

	if (!args[1])
		return (1);
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
			printf("'%s': not a valid identifier\n", args[i]);
		i++;
	}
	del_envs(&args[1]); */
	return (0);
}
