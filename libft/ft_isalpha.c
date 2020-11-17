/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:29:55 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/16 17:46:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return(1);
	return(0);
}

int		main(void)
{
	int c;
	int a;
	int b; 

	c = 110;
	a = 166;
	b = 92;

	printf("essais : %d \n", ft_isalpha(c));
	printf("essais : %d \n", ft_isalpha(a));
	printf("essais : %d \n", ft_isalpha(b));
	printf("vrai : %d \n", isalpha(c));
	printf("vrai : %d \n", isalpha(a));
	printf("vrai : %d \n", isalpha(b));
	return (0);
}