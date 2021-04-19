/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/04/19 15:28:43 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_flags_c(int c, t_point *conv)
{
	if (conv->width > 1)
	{
		if (conv->minus == 1)
		{
			ft_write(c, 1);
			while (conv->width-- != 1)
				ft_write(' ', 1);
		}
		else
		{
			while (conv->width-- != 1)
				ft_write(' ', 1);
			ft_write(c, 1);
		}
	}
	else
		ft_write(c, 1);
}

void	ft_conv_flags_pc(t_point *conv)
{
	if (conv->width > 1)
	{
		if (conv->minus == 1)
		{
			ft_write('%', 1);
			while (conv->width-- != 1)
				ft_write(' ', 1);
		}
		else if (conv->zero == 1)
		{
			while (conv->width-- != 1)
				ft_write('0', 1);
			ft_write('%', 1);
		}
		else
		{
			while (conv->width-- != 1)
				ft_write(' ', 1);
			ft_write('%', 1);
		}
	}
	else
		ft_write('%', 1);
}

void	ft_conv_flags_s_width(char *str, t_point *conv)
{
	int	i;

	i = 0;
	conv->width = conv->width - conv->size;
	if (conv->minus == 1)
	{
		while (conv->size-- != 0)
			ft_write(str[i++], 1);
		while (conv->width-- != 0)
			ft_write(' ', 1);
	}
	else if (conv->zero == 1)
	{
		while (conv->width-- != 0)
			ft_write('0', 1);
		while (conv->size-- != 0)
			ft_write(str[i++], 1);
	}
	else
	{
		while (conv->width-- != 0)
			ft_write(' ', 1);
		while (conv->size-- != 0)
			ft_write(str[i++], 1);
	}
}

void	ft_conv_flags_s(char *str, t_point *conv)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	conv->size = ft_strlen(str);
	if (conv->dot == 1)
		if (conv->precision < conv->size)
			conv->size = conv->precision;
	if (conv->width > conv->size)
		ft_conv_flags_s_width(str, conv);
	else
	{
		while (conv->size != 0)
		{
			ft_write(str[i++], 1);
			conv->size--;
		}
	}
}

int	ft_conv_flags(va_list arg, t_point *conv)
{
	if (conv->type == 1)
		ft_conv_flags_c(va_arg(arg, int), conv);
	if (conv->type == 2)
		ft_conv_flags_d(va_arg(arg, int), conv);
	if (conv->type == 3)
		ft_conv_flags_s(va_arg(arg, char *), conv);
	if (conv->type == 4)
		ft_conv_flags_p(va_arg(arg, void *), conv);
	if (conv->type == 10)
		ft_conv_flags_pc(conv);
	ft_cln(conv);

	return (1);
}
