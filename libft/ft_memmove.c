/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:08:00 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char	src1[15] = "bonjour";
	char	src[15] = "bonjour";
	size_t	len;

	len = 7;
	memcpy(src1 + 3, src1, len);
	memcpy(src + 3, src, len);
	printf("memmove dst = %s\n", src + 3);
	printf("memcpy dst  = %s\n", src1 + 3);
	printf("memmove src = %s\n", src);
	printf("memcpy src  = %s\n", src);
	return (0);
}