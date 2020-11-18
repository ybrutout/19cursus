/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:08:00 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/18 18:34:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		main(void)
{
	//char	dst[10] = "coucou ca";
	char	src[15] = "bonjour";
	size_t	len;

	len = 7;
	printf("adresse avant ; %p\n", src);
	memcpy(src + 3, src, len);
	printf("dst = %s\n", src);
	printf("adresse apres : %p\n", src);
	return (0);
}