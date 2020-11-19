/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:51:50 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
		return (1);
	return (0);
}

int		main(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 151511561;
	b = 0177;
	c = 158;
	d = 178;
	printf("faux : %d \n", ft_isascii(a));
	printf("faux : %d \n", ft_isascii(b));
	printf("faux : %d \n", ft_isascii(c));
	printf("faux : %d \n", ft_isascii(d));
	printf("vrai : %d \n", isascii(a));
	printf("vrai : %d \n", isascii(b));
	printf("vrai : %d \n", isascii(c));
	printf("vrai : %d \n", isascii(d));
	return (0);
}