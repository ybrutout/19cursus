/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:50:34 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}

int		main(void)
{
	char 	dst[20] = "coucou comment ";
	char 	dst2[20] = "coucou comment ";
	//char	src[35] = "yannah et loohan et nahama";
	size_t	n;

	n = 10;
	printf("F avant : %s\n", dst);
	printf("V avant : %s\n", dst2);
	ft_memcpy(dst, dst + 1, n);
	memcpy(dst2, dst2 + 1, n);
	printf("F apres : %s\n", dst);
	printf("V apres : %s\n", dst2);
	return (0);
}