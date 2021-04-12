/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/12 15:32:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	ft_cln(t_point *conv)
{
	conv->dot = 0;
	conv->minus = 0;
	conv->precision = 0;
	conv->width = 0;
	conv->zero = 0;
	conv->type = 0;
	conv->size = 0;
}

int	ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen_nb(long i, int base)
{
	long int	len;

	len = 0;
	if (i < 0)
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

char	*ft_cpy(char *dst, int flag, t_point conv, int src_size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = conv.str;
	if (flag > 9)
		dst[conv.precision--] = '\0';
	if (flag < 9)
	{
		if (conv.width < src_size)
			conv.width = src_size;
		dst[conv.width--] = '\0';
	}
	if (flag == 0)
	{
		while (conv.width >= 0 || src_size > -1)
		{
			if (--src_size > -1)
				dst[conv.width--] = str[src_size];
			else if (src_size <= -1)
			{
				dst[conv.width--] = ' ';
			}
		}
	}
	else if (flag == 1)
	{
		while (i <= conv.width)
		{
			if (src_size-- > 0)
			{
				dst[i++] = str[j++];
			}
			else
				dst[i++] = ' ';
		}
	}
	else if (flag == 2)
	{
		while (conv.width >= 0)
		{
			if (--src_size > -1)
				dst[conv.width--] = str[src_size--];
			else if (src_size <= -1)
				dst[conv.width--] = '0';
		}
	}
	else if (flag == 10)
	{
		while (conv.precision >= 0)
		{
			if (--src_size > -1)
				dst[conv.precision--] = str[src_size];
			else if (src_size <= -1)
				dst[conv.precision--] = ' ';
		}
	}
	return (dst);
}
