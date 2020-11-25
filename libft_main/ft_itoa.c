/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:41:21 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/25 11:06:44 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_strnbr(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i = i + 2;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*c;
	long int	size;
	long int	new_n;

	new_n = n;
	size = ft_strnbr(new_n);
	c = malloc(sizeof(char) * size);
	if (!c)
		return (NULL);
	if (new_n < 0)
	{
		c[0] = '-';
		new_n *= -1;
	}
	c[--size] = '\0';
	if (new_n == 0)
		c[0] = '0';
	while (new_n)
	{
		c[--size] = new_n % 10 + 48;
		new_n = new_n / 10;
	}
	return (c);
}

int					main(void)
{
	char *i3;

	i3 = ft_itoa(-2147483647);
	printf("-0 ; %s\n", i3);
	return (0);
}
