/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/07 17:51:18 by ybrutout         ###   ########.fr       */
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

char	*ft_cpy(char *dst, char *src, int flag, int size, int width)
{
	int	i;
	int	src_size;

	i = 0;
	src_size = ft_strlen(src);
	dst[size--] = '\0';
	if (flag == 0)
	{
		while (size >= 0)
		{
			if (src_size-- > -1)
				dst[size--] = src[src_size--];
			if ()
				;
		}
	}
}
