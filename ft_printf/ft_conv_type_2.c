/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_type_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:25:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/07 14:55:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_u(int i)
{
	char			*str;
	int				size;
	unsigned int	nw_i;

	nw_i = (unsigned)i;
	size = ft_strlen_nb(nw_i, 10);
	str = (char *)malloc(sizeof (char) * size + 1);
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

static void	ft_conv_x_2(unsigned int nw_i, int size, char *str)
{
	while (nw_i > 17)
	{
		unsigned int	modulo;

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
}

char	*ft_conv_x_1(int i)
{
	char			*str;
	int				size;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	str = (char *)malloc(sizeof (char) * size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	ft_conv_x_2(nw_i, size, str);
	return (str);
}

static void	ft_conv_X_2(unsigned int nw_i, int size, char *str)
{
	while (nw_i > 17)
	{
		unsigned int modulo;

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
}

char	*ft_conv_X_1(int i)
{
	char			*str;
	int				size;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	str = (char *)malloc(sizeof (char) * size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	ft_conv_X_2(nw_i, size, str);
	return (str);
}
