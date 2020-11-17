/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:51:50 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/17 10:59:15 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 177)
		return (1);
	return (0);
}

int		main(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 0;
	b = 177;
	c = 58;
	d = 176;
	printf("faux : %d /n", ft_isascii(a));
	printf("faux : %d /n", ft_isascii(b));
	printf("faux : %d /n", ft_isascii(c));
	printf("faux : %d /n", ft_isascii(d));
	printf("vrai : %d /n", isascii(a));
	printf("vrai : %d /n", isascii(b));
	printf("vrai : %d /n", isascii(c));
	printf("vrai : %d /n", isascii(d));
	return (0);
}