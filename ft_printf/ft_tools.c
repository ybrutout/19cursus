/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/22 16:22:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_0x(void)
{
	ft_write('0', 1);
	ft_write('x', 1);
}

void	ft_putnbr(unsigned long long int nb, int base, char *str_base)
{
	unsigned long long int	nw_base;

	nw_base = (unsigned long long int)base;
	if (nb < 0)
	{
		ft_write('-', 1);
		nb = nb * -1;
	}
	if (nb >= nw_base)
		ft_putnbr((nb / base), base, str_base);
	ft_write(str_base[nb % base], 1);
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

int	ft_strlen_nb(unsigned long long int i, int base)
{
	long long int			len;
	unsigned long long int	nw_base;

	len = 0;
	nw_base = (unsigned long long int)base;
	while (i > (nw_base - 1))
	{
		i = i / nw_base;
		len++;
	}
	len = len + 1;
	return (len);
}
