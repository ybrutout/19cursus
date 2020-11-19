/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:01:38 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if(c >= 'a' && c <= 'z')
		c = (c - 32);
	return (c);
}

int		main(void)
{
	int a;
	int b;
	int c;
	int d;
	int e; 

	a = 97;
	b = 122;
	c = 106;
	d = 96;
	e = -2147483648;
	printf("faux : %d \n", ft_toupper(a));
	printf("faux : %d \n", ft_toupper(b));
	printf("faux : %d \n", ft_toupper(c));
	printf("faux : %d \n", ft_toupper(d));
	printf("faux : %d \n", ft_toupper(e));
	printf("vrai : %d \n", toupper(a));
	printf("vrai : %d \n", toupper(b));
	printf("vrai : %d \n", toupper(c));
	printf("vrai : %d \n", toupper(d));
	printf("vrai : %d \n", toupper(e));
	return (0);
}