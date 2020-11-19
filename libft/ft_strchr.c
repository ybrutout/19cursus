/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:56:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 12:27:39 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *src;

	src = (char *)s;
	while (src)
	{
		if ( *src == (char)c)
			return (src);
		src++;
	}
	if (*src == (char)c)
		return(src);
	return (0);
}
