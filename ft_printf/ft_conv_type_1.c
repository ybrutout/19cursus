/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_type_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:28:40 by mushu             #+#    #+#             */
/*   Updated: 2021/04/14 14:45:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_d(int j)
{
	char		*str;
	int			size;

	size = ft_strlen_nb(j, 10);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	str[size--] = '\0';
	if (j < 0)
	{
		str[0] = '-';
		j *= -1;
	}
	while (j)
	{
		str[size--] = j % 10 + 48;
		j = j / 10;
	}
	return (str);
}

char	*ft_conv_c(char c)
{
	char	*str;

	str = (char *)malloc(sizeof (char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_conv_s_null(char *str)
{
	char	*nw_str;

	if (!str)
	{
		nw_str = malloc(sizeof(char) * 7);
		if (!nw_str)
			return(0);
		nw_str[0] = '(';
		nw_str[1] = 'n';
		nw_str[2] = 'u';
		nw_str[3] = 'l';
		nw_str[4] = 'l';
		nw_str[5] = ')';
		nw_str[6] = '\0';
		return (nw_str);
	}
	return (NULL);
}

char	*ft_conv_s(char	*str)
{
	char		*nw_str;
	int			size;
	int			i;

	if (!str)
	{
		str = ft_conv_s_null(str);
		if (!str)
			return(NULL);
	}
	size = ft_strlen(str);
	i = -1;
	nw_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!nw_str)
		return (NULL);
	while (str[++i])
		nw_str[i] = str[i];
	nw_str[size] = '\0';
	return (nw_str);
}

static void	ft_conv_p_2(unsigned long long int new_n, \
					unsigned long long int size, char *c)
{
	unsigned long long int	modulo;

	while (new_n > 17)
	{
		modulo = new_n % 16;
		if (0 <= modulo && modulo <= 9)
			c[--size] = modulo + 48;
		if (10 <= modulo && modulo <= 16)
			c[--size] = modulo + 87;
		new_n = new_n / 16;
	}
	if (modulo < 17)
	{
		if (modulo <= 9)
			c[--size] = modulo + 48;
		if (10 <= modulo && modulo <= 16)
			c[--size] = modulo + 87;
	}
}

char	*ft_conv_p_1(void *adress)
{
	char					*c;
	unsigned long long int	size;
	unsigned long long int	new_n;

	new_n = (unsigned long long int)adress;
	size = (ft_strlen_nb(new_n, 16)) + 3;
	c = (char *)malloc(sizeof(char) * size);
	if (!c)
		return (NULL);
	c[--size] = '\0';
	c[0] = '0';
	c[1] = 'x';
	ft_conv_p_2(new_n, size, c);
	return (c);
}