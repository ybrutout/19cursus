/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:41:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/15 16:53:56 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_flags_d(int i, t_point *conv)
{
	conv->size = ft_strlen_nb(i);
	if (i < 0)
		conv->size--;
	if (conv->dot == 1 && (conv->precision > conv->size))
		conv->precision = conv->precision - conv->size;
	else
		conv->precision = 0;
	if (conv->width > (conv->size + conv->precision))
	{
		conv->width = (conv->width - (conv->size + conv->precision));
		if (i < 0)
			conv->width--;
		if (conv->minus == 1)
		{
			if (i < 0 && conv->precision != 0)
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
			while (conv->width-- != 0)
				ft_write(' ', 1);
		}
		else if (conv->zero == 1 && conv->dot == 0)
		{
			if (i < 0 )
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while (conv->width-- != 0)
				ft_write('0', 1);
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
		}
		else
		{
			while (conv->width-- != 0)
				ft_write(' ', 1);
			if (i < 0 && conv->precision != 0)
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
		}
	}
	else
	{
		if (i < 0 && conv->precision != 0)
		{
			ft_write('-', 1);
			i = i * -1;
		}
		while (conv->precision-- != 0)
			ft_write('0', 1);
		ft_putnbr(i);
	}
}
