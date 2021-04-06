/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:28:40 by mushu             #+#    #+#             */
/*   Updated: 2021/04/06 11:01:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_nb(long i, int base)
{
	long int	len;

	len = 0;
	if(i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > base - 1)
	{
		i = i / base;
		len++;
	}
	len = len + 1;
	return (len);
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char			*ft_conv_d(int j)
{
	char		*str;
	int			size;

	size = ft_strlen_nb(j, 10);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size--] = '\0';
	if (j < 0)
	{
		str[0] = '-';
		j *= -1;
	}
	while(j)
	{
		str[size--] = j % 10 + 48;
		j = j / 10;
	}
	return (str);
}

char			*ft_conv_c(va_list arg)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof (char) * 2)))
		return (NULL);
	str[0] = va_arg(arg, int);
	str[1] = '\0';
	return (str);
}

char			*ft_conv_s(char	*str)
{

	char		*nw_str;
	int			size;
	int			i;

	size = ft_strlen(str);
	i = -1;
	if(!(nw_str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str[++i])
		nw_str[i] = str[i];
	return (nw_str);
}

char					*ft_conv_p(void *adress)
{
	char					*c;
	unsigned long long int	size;
	unsigned long long int	new_n;
	int						modulo;

	new_n = (unsigned long long int)adress;
	size = (ft_strlen_nb(new_n, 16)) + 3;
	if (!(c = (char *)malloc(sizeof(char) * size)))
		return(0);
	c[--size] = '\0';
	c[0] = '0';
	c[1] = 'x';
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
	return (c);
}

char				*ft_conv_u(int i)
{
	char			*str;
	int				size;
	unsigned int	nw_i;

	nw_i = (unsigned)i;
	size = ft_strlen_nb(nw_i, 10);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size--] = '\0';
	while(nw_i)
	{
		str[size--] = nw_i % 10 + 48;
		nw_i = nw_i / 10;
	}
	return (str);

}

char				*ft_conv_x(int i)
{
	char			*str;
	int				size;
	unsigned int	modulo;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	if (!(str = (char *)malloc(sizeof (char) * size + 1)))
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


char				*ft_conv_X(int i)
{
	char			*str;
	int				size;
	unsigned int	modulo;
	unsigned int	nw_i;

	nw_i = (unsigned) i;
	size = ft_strlen_nb(nw_i, 16);
	if (!(str = (char *)malloc(sizeof (char) * size + 1)))
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

int				ft_conv_type(char *form, va_list arg, t_point *conv)
{

	if (*form == 'c')
	{
		if (!((*conv).str = ft_conv_c(arg)))
			return (0);
	}
	else if(*form == 'd' || *form == 'i')
	{
		if(!((*conv).str = ft_conv_d(va_arg(arg, int))))
			return (0);
	}
	else if (*form == 's')
	{
		if (!((*conv).str = ft_conv_s(va_arg(arg, char*))))
			return(0);
	}
	else if (*form == 'p')
	{
		if (!((*conv).str = ft_conv_p(va_arg(arg, void*))))
			return (0);
	}
	else if(*form == 'u')
	{
		if(!((*conv).str = ft_conv_u(va_arg(arg, int))))
			return (0);

	}
	else if (*form == 'x')
	{
		if(!((*conv).str = ft_conv_x(va_arg(arg, int))))
			return (0);
	}
	else if (*form == 'X')
	{
		if(!((*conv).str = ft_conv_X(va_arg(arg, int))))
			return (0);
	}
	if (*(*conv).str)
	{
		ft_write((*conv).str, 1);
		free((*conv).str);
		ft_cln(conv);
	}
	return (1);
}
