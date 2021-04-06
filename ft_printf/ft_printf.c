/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:26:47 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/06 11:05:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_write(char *str, int a)
{
	int				i;
	static int		ret;

	i = 0;
	if (!ret)
		ret = 0;
	if (a == 1)
	{
		while(str[i])
		{
			write(1, &str[i], 1);
			i++;
			ret++;
		}
	}
	else if (a == 2)
	{
		write(1, str, 1);
		ret++;
	}
	return(ret);
}

int					ft_check_type(char c)
{
	if (c == '-' ||  c == '0')
		return (1);
	if (c > '0' && c <= '9')
		return(2);
	if (c == '*'|| c == '.')
		return (3);
	if (c == 'd' || c == 'i' || c == 's' || c == 'p' || c == 'c' || c == 'x' || c == 'X' || c == 'u')
		return (4);
	return (0);
}

void		ft_cln(t_point *conv)
{
	conv->dot = 0;
	conv->minus = 0;
	conv->precision = 0;
	conv->width = 0;
	conv->zero = 0;
}

int					ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
	int 			type;
	char			*form;
	va_list			arg;
	t_point			conv;

	form = (char *)format;
	va_start(arg, format);
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '%')
			{
				ft_write(form, 2);
				form++;
			}
			else
			{
				if ((type = ft_check_type(*form)) == 1)
				{
					i = ft_conv_flag(form, &conv);
					form = &form[i];
				}
				if((type = ft_check_type(*form)) == 2)
				{
					i = ft_conv_width(form, &conv);
					form = &form[i];
				}
				if ((type = ft_check_type(*form)) == 3)
				{
					i = ft_conv_precision(form, &conv);
					form = &form[i];
				}
				printf("minus = %d\n zero = %d \n precision = %d \n dot = %d \n", conv.minus, conv.zero, conv.precision, conv.dot);
				if((type = ft_check_type(*form)) == 4)
				{
					if (!(i = ft_conv_type(form, arg, &conv)))
						return (0);
					form = &form[i];
				}
				printf("minus = %d\n zero = %d \n precision = %d \n dot = %d \n", conv.minus, conv.zero, conv.precision, conv.dot);
			}
		}
		else
		{
			ft_write(form, 2);
			form++;
		}
	}
	ret = ft_write(form, 0);
	va_end(arg);
	return (ret);
}
