/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:24:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/18 12:59:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char *s;
	size_t i; 

	i = 0;
	s = b; 
	while (i < len)
	{
		s[i] = c;
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