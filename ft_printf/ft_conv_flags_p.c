/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:35:00 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/22 10:31:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_flags_p_minus(unsigned long long int nw_ad, t_point *conv)
{
	if (conv->dot != 2)
	{
		while (conv->precision-- != 0)
			ft_write('0', 1);
	}
	ft_write('0', 1);
	ft_write('x', 1);
	if (conv->dot != 2)
		ft_putnbr(nw_ad, 16, "0123456789abcdef");
	else
		ft_write(' ', 1);
	while (conv->width-- != 0)
		ft_write(' ', 1);
}

static void	ft_conv_flags_p_zero(unsigned long long int nw_ad, t_point *conv)
{
	if (conv->dot == 1)
		while (conv->width-- != 0)
			ft_write(' ', 1);
	while (conv->width-- > 0)
		ft_write('0', 1);
	while (conv->precision-- != 0)
		ft_write('0', 1);
	ft_write('0', 1);
	ft_write('x', 1);
	ft_putnbr(nw_ad, 16, "0123456789abcdef");
}

static void	ft_conv_flags_p_width(unsigned long long int nw_ad, t_point *conv)
{
	conv->width = conv->width - (conv->size + conv->precision);
	if (conv->minus == 1)
		ft_conv_flags_p_minus(nw_ad, conv);
	else if (conv->zero == 1)
		ft_conv_flags_p_zero(nw_ad, conv);
	else
	{
		while (conv->width-- > 0)
			ft_write(' ', 1);
		if (conv->dot != 2)
		{
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_write('0', 1);
			ft_write('x', 1);
			ft_putnbr(nw_ad, 16, "0123456789abcdef");
		}
		else
		{
			ft_write(' ', 1);
			ft_write('0', 1);
			ft_write('x', 1);
		}
	}
}

static void	ft_conv_flags_p_dot(unsigned long long int nw_ad, t_point *conv)
{
	if (conv->precision < 0)
		conv->size = 11;
	if (conv->precision > conv->size)
		conv->precision = conv->precision - conv->size;
	else if ((conv->precision == 0 && nw_ad == 0))
		conv->dot = 2;
	else
		conv->precision = 0;
	if ((conv->width > (conv->precision + conv->size)) || \
		(conv->dot == 2 && conv->width == conv->size))
		ft_conv_flags_p_width(nw_ad, conv);
	else
	{
		ft_write('0', 1);
		ft_write('x', 1);
		if (conv->dot != 2)
		{
			if (conv->size < 11)
				conv->precision = conv->precision + 2;
			while (conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(nw_ad, 16, "0123456789abcdef");
		}
	}
}

void	ft_conv_flags_p(void *adress, t_point *conv)
{
	unsigned long long int	nw_ad;

	nw_ad = (unsigned long long int) adress;
	conv->size = ((ft_strlen_nb(nw_ad, 16)) + 2);
	if (conv->dot == 1)
		ft_conv_flags_p_dot(nw_ad, conv);
	else if (conv->width > conv->size)
		ft_conv_flags_p_width(nw_ad, conv);
	else
	{
		ft_write('0', 1);
		ft_write('x', 1);
		ft_putnbr(nw_ad, 16, "0123456789abcdef");
	}
}
