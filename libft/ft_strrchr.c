/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:29:56 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 12:27:51 by ybrutout         ###   ########.fr       */
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
	return ("\0");
}
