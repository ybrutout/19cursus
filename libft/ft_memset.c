/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:24:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:18 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *new_b;
	size_t i; 

	i = 0;
	new_b = (char *)b; 
	while (i < len)
	{
		new_b[i] = c;
		i++;
	}
	
	return (b);
}

int		main(void)
{
	char	src1[50] = "yannah loohan nahama";
	char	src2[50] = "yannah loohan nahama";
	int		c;
	size_t	len;

	c = '-';
	len = 2;
	printf("avant memset : %s\n", src1);
	printf("après memset : %s\n", ft_memset(src1, c, len));
	printf("vrai avant memset : %s\n", src2);
	printf("vrai après memset : %s\n", memset(src2, c, len));
	return(0);
}