/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:29:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/25 00:21:21 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ms_puterr_2arg(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str2, STDERR_FILENO);
}

void	perror_2(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	if (str2 && !*str2)
		ft_putstr_fd(": ", 2);
	perror(str2);
}
