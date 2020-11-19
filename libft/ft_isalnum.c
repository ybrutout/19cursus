/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:41:30 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:42 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		main(void)
{
	int c;
	int a;
	int b;
  	int e;
	int f;
	int g;
	int h;

	c = 110;
	a = 166;
	b = 92;
	printf("essais : %d \n", ft_isalnum(c));
	printf("essais : %d \n", ft_isalnum(a));
	printf("essais : %d \n", ft_isalnum(b));
	printf("vrai : %d \n", isalnum(c));
	printf("vrai : %d \n", isalnum(a));
	printf("vrai : %d \n", isalnum(b));
	e = 57;
	f = 48;
	g = 47;
	h = 58;
	printf("essais : %d \n", ft_isalnum(e));
	printf("essais : %d \n", ft_isalnum(f));
	printf("essais : %d \n", ft_isalnum(g));
	printf("essais : %d \n", ft_isalnum(h));
	printf("vrai : %d \n", isalnum(e));
	printf("vrai : %d \n", isalnum(f));
	printf("vrai : %d \n", isalnum(g));
	printf("vrai : %d \n", isalnum(h));
	return (0);
}
