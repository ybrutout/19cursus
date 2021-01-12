/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:31:48 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/14 17:26:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *b, const void *a, size_t n)
{
	unsigned char	*src;
	char			*dest;
	int				i;

	i = -1;
	src = (unsigned char *)a;
	dest = (char *)b;
	if (a == 0 && b == 0)
		return (NULL);
	else if (dest > (char *)src)
	{
		while (n > 0)
		{
			--n;
			dest[n] = src[n];
		}
	}
	else if (dest <= (char *)src)
	{
		while ((size_t)++i < n)
			dest[i] = src[i];
	}
	return (dest);
}
