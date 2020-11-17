/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:28:12 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/17 10:44:05 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		main(void)
{
	int e;
	int f;
	int g;
	int h;

	e = 57;
	f = 48;
	g = 47;
	h = 58;
	printf("essais : %d \n", ft_isdigit(e));
	printf("essais : %d \n", ft_isdigit(f));
	printf("essais : %d \n", ft_isdigit(g));
	printf("essais : %d \n", ft_isdigit(h));
	printf("vrai : %d \n", isdigit(e));
	printf("vrai : %d \n", isdigit(f));
	printf("vrai : %d \n", isdigit(g));
	printf("vrai : %d \n", isdigit(h));
	return (0);
}
