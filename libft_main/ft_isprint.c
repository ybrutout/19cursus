/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:16:29 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return(1);
	return (0);
}

int		main(void)
{
	int a;
	int b;
	int c; 
	int d; 
	int e;

	a = 32;
	b = 126; 
	c = 74;
	d = 31;
	e = 127;
	printf("faux : %d \n", ft_isprint(a));
	printf("faux : %d \n", ft_isprint(b));
	printf("faux : %d \n", ft_isprint(c));
	printf("faux : %d \n", ft_isprint(d));
	printf("faux : %d \n", ft_isprint(e));
	printf("vrai : %d \n", ft_isprint(a));
	printf("vrai : %d \n", ft_isprint(b));
	printf("vrai : %d \n", ft_isprint(c));
	printf("vrai : %d \n", ft_isprint(d));
	printf("vrai : %d \n", ft_isprint(e));
	return (0);
}