/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_type_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:25:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/07 14:23:40 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_conv_u(int i)
{
	char			*str;
	int				size;
	unsigned int	nw_i;

	nw_i = (unsigned)i;
	size = ft_strlen_nb(nw_i, 10);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (nw_i)
	{
		str[size--] = nw_i % 10 + 48;
		nw_i = nw_i / 10;
	}
	return (str);
}

char	*ft_conv_x(int i)
{
	char			*str;
	int				size;
	unsigned int	modulo;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	str = (char *)malloc(sizeof (char) * size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	while (nw_i > 17)
	{
		modulo = nw_i % 16;
		if (modulo <= 9)
			str[--size] = modulo + 48;
		if (10 <= modulo && modulo <= 16)
			str[--size] = modulo + 87;
		nw_i = nw_i / 16;
	}
	if (nw_i < 17)
	{
		if (nw_i <= 9)
			str[--size] = nw_i + 48;
		if (10 <= nw_i && nw_i <= 16)
			str[--size] = nw_i + 87;
	}
	return (str);
}

char	*ft_conv_X(int i)
{
	char			*str;
	int				size;
	unsigned int	modulo;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	str = (char *)malloc(sizeof (char) * size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	while (nw_i > 17)
	{
		modulo = nw_i % 16;
		if (modulo <= 9)
			str[--size] = modulo + 48;
		if (10 <= modulo && modulo <= 16)
			str[--size] = modulo + 55;
		nw_i = nw_i / 16;
	}
	if (nw_i < 17)
	{
		if (nw_i <= 9)
			str[--size] = nw_i + 48;
		if (10 <= nw_i && nw_i <= 16)
			str[--size] = nw_i + 55;
	}
	return (str);
}
