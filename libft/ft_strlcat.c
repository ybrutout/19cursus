/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:50:31 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 12:54:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (ft_strlen(dst) < dstsize)
		size = ft_strlen(src) + ft_strlen(dst);
	else
		size = dstsize + ft_strlen(src);
	j = 0;
	while (dst[j] && dstsize)
	{
		j++;
		dstsize--;
	}
	i = 0;
	while (src[i] && i < dstsize - 1 && dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (dstsize)
		dst[j + i] = '\0';
	return (size);
}
