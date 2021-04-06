/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:26:47 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/06 16:35:30 by ybrutout         ###   ########.fr       */
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
			else if ((ft_check_form(*form)) > 0)
			{
				if ((ft_check_form(*form)) == 1)
				{
					i = ft_check_flag(form, &conv);
					form = &form[i];
				}
				if((ft_check_form(*form)) == 2)
				{
					i = ft_check_width(form, &conv, arg);
					form = &form[i];
				}
				if ((ft_check_form(*form)) == 3)
				{
					i = ft_check_precision(form, &conv, arg);
					form = &form[i];
				}
				if((ft_check_form(*form)) == 4)
				{
					i = ft_check_type(form, &conv);
					form = &form[i];
				}
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
