/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:48:32 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 16:41:40 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*src1;
	char			*dst1;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	while (src1[i] != '\0')
	{
		i++;
	}

	while (dstsize != 0 && src1[j] != '\0' && j < dstsize)
	{
		dst1[j] = src1[j];
		j++; 
	}
	dst1[j + 1] = '\0'; 
	return(i);
}