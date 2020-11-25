/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:43:57 by yannahbruto       #+#    #+#             */
/*   Updated: 2020/11/25 09:17:31 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnbr(int n)
{	
	size_t		i;

	i = 1;
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
	i = i + 1;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*c;
	size_t		size;
	size_t		i;

	if (!n)
		return (NULL);
	size = ft_strnbr(n);
	c = malloc(sizeof(char) * size);
	i = 0;
	if (!c)
		return(NULL);
	if (n < 0)
	{
		c[i++] = '-';
		n *= -1;
	}
	while (n)
	{
		c[i++] = n % 10 + 48;
		n = n / 10;
	}
	c[i] = '\0';
	return(c);
}