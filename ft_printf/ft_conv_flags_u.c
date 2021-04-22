/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:14:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/22 10:31:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_flags_u_minus(unsigned long long int nb, t_point *conv)
{
	if (conv->dot != 2)
	{
		while (conv->precision-- != 0)
			ft_write('0', 1);
		ft_putnbr(nb, 10, "0123456789");
	}
	else
		ft_write(' ', 1);
	while (conv->width-- > 0)
		ft_write(' ', 1);
}

static void	ft_conv_flags_u_zero(unsigned long long int nb, t_point *conv)
{
	if (conv->dot > 0 && conv->precision > 0)
		while (conv->width-- > 0)
			ft_write(' ', 1);
	while (conv->width-- > 0)
		ft_write('0', 1);
	while (conv->precision-- != 0)
		ft_write('0', 1);
	if (conv->dot != 2)
		ft_putnbr(nb, 10, "0123456789");
	else
		ft_write(' ', 1);
}

static void	ft_conv_flags_u_width(unsigned long long int nb, t_point *conv)
{
	conv->width = conv->width - (conv->size + conv->precision);
	if (conv->minus == 1)
		ft_conv_flags_u_minus(nb, conv);
	else if (conv->zero == 1)
		ft_conv_flags_u_zero(nb, conv);
	else
	{
		while (conv->width-- > 0)
			ft_write(' ', 1);
		if (conv->dot != 2)
		{
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(nb, 10, "0123456789");
		}
		else
			ft_write(' ', 1);
	}
}

static void	ft_conv_flags_u_dot(unsigned long long int nb, t_point *conv)
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
		ft_conv_flags_u_width(nb, conv);
	else
	{
		if (conv->dot != 2)
		{
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(nb, 10, "0123456789");
		}
	}
}

void	ft_conv_flags_u(unsigned int nb, t_point *conv)
{
	conv->size = ft_strlen_nb(nb, 10);
	if (conv->dot == 1)
		ft_conv_flags_u_dot(nb, conv);
	else if (conv->width > 0)
		ft_conv_flags_u_width(nb, conv);
	else
	{
		ft_putnbr(nb, 10, "0123456789");
	}
}
