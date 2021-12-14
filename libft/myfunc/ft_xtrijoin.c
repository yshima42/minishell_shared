/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtrijoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:02:14 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 09:39:57 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xtrijoin(char const *s1, char const *s2, char const *s3)
{
	return (ft_xstrjoin(s1, ft_xstrjoin(s2, s3)));
}
