/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:41:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/22 10:30:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_flags_d_minus(int sign, unsigned int nb, t_point *conv)
{
	if (conv->dot != 2)
	{
		if (sign == 1)
			ft_write('-', 1);
		while (conv->precision-- != 0)
			ft_write('0', 1);
		ft_putnbr(nb, 10, "0123456789");
	}
	else
		ft_write(' ', 1);
	while (conv->width-- > 0)
		ft_write(' ', 1);
}

static void	ft_conv_flags_d_zero(int sign, unsigned int nb, t_point *conv)
{
	if (conv->dot > 0 && conv->precision > 0)
		while (conv->width-- > 0)
			ft_write(' ', 1);
	if (sign == 1)
		ft_write('-', 1);
	while (conv->width-- > 0)
		ft_write('0', 1);
	while (conv->precision-- != 0)
		ft_write('0', 1);
	if (conv->dot != 2)
		ft_putnbr(nb, 10, "0123456789");
	else
		ft_write(' ', 1);
}

static void	ft_conv_flags_d_width(unsigned int nb, int sign, t_point *conv)
{
	if (sign == 1)
		conv->size++;
	conv->width = conv->width - (conv->size + conv->precision);
	if (conv->minus == 1)
		ft_conv_flags_d_minus(sign, nb, conv);
	else if (conv->zero == 1)
		ft_conv_flags_d_zero(sign, nb, conv);
	else
	{
		while (conv->width-- > 0)
			ft_write(' ', 1);
		if (conv->dot != 2)
		{
			if (sign == 1)
				ft_write('-', 1);
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(nb, 10, "0123456789");
		}
		else
			ft_write(' ', 1);
	}
}

static void	ft_conv_flags_d_dot(unsigned long int nb, int sign, t_point *conv)
{
	if (conv->precision >= 0)
		conv->zero = 0;
	if (conv->precision > conv->size)
		conv->precision = conv->precision - conv->size;
	else if (conv->precision == 0 && nb == 0)
		conv->dot = 2;
	else
		conv->precision = 0;
	if ((conv->width > (conv->precision + conv->size)) || \
		((conv->dot == 2) && (conv->width == conv->size)))
		ft_conv_flags_d_width(nb, sign, conv);
	else
	{
		if (conv->dot != 2)
		{
			if (sign == 1)
				ft_write('-', 1);
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(nb, 10, "0123456789");
		}
	}
}

void	ft_conv_flags_d(int i, t_point *conv)
{
	unsigned int	nb;
	int				sign;

	sign = 0;
	if (i < 0)
	{
		nb = i * -1;
		sign = 1;
	}
	else
		nb = i;
	conv->size = ft_strlen_nb(nb, 10);
	if (conv->dot == 1)
		ft_conv_flags_d_dot(nb, sign, conv);
	else if (conv->width > 0)
		ft_conv_flags_d_width(nb, sign, conv);
	else
	{
		if (sign == 1)
			ft_write('-', 1);
		ft_putnbr(nb, 10, "0123456789");
	}
}
