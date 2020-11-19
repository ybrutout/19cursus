/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:56:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 14:24:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char *src;
    int i;

	src = (char *)s;
    i = ft_strlen(src) - 1;
	while (src[i])
	{
		if ( src[i] == (char)c)
			return (&src[i]);
		i--;
	}
	if (*src == (char)c)
		return(src);
	return (0);
}
