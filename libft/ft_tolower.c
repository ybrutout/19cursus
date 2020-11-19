/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:21:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
		c = (c + 32);
	return (c);
}

int		main(void)
{
	int a;
	int b;
	int c;
	int d;
	int e; 

	a = 65;
	b = 90;
	c = 74;
	d = 96;
	e = 1;
	printf("faux : %d \n", ft_tolower(a));
	printf("faux : %d \n", ft_tolower(b));
	printf("faux : %d \n", ft_tolower(c));
	printf("faux : %d \n", ft_tolower(d));
	printf("faux : %d \n", ft_tolower(e));
	printf("vrai : %d \n", tolower(a));
	printf("vrai : %d \n", tolower(b));
	printf("vrai : %d \n", tolower(c));
	printf("vrai : %d \n", tolower(d));
	printf("vrai : %d \n", tolower(e));
	return (0);
}