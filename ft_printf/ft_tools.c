/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/15 15:58:51 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	long long int	i;

	i = (long long int)nb;
	if (i < 0)
	{
		ft_write('-', 1);
		i = i * -1;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_write((i % 10 + '0'), 1);
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

int	ft_strlen_nb(long i)
{
	long int	len;

	len = 0;
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > 9)
	{
		i = i / 10;
		len++;
	}
	len = len + 1;
	return (len);
}
