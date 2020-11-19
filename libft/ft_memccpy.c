/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:05:29 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 12:26:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,int c, size_t n)
{
	char	*new_dst;
	char	*new_src;
	size_t	i;

	new_dst = (char *) dst;
	new_src = (char *) src;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
        if (new_src[i] == c)
        {
            i++;
            return (&dst[i]);
        }
		i++;
	}
	return (0);
}
