/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:26:47 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/12 10:48:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *str, int a)
{
	int				i;
	static int		ret;

	i = 0;
	if (!ret)
		ret = 0;
	if (a > 0)
	{
		a--;
		while (i <= a)
		{
			write(1, &str[i], 1);
			ret++;
			i++;
		}
	}
	else if (a == 0)
	{
		write(1, str, 1);
		ret++;
	}
	return (ret);
}

char	*ft_printf2(char *form, t_point *conv, va_list arg)
{
	if ((ft_check_form(*form)) > 0)
	{
		if ((ft_check_form(*form)) == 1)
			form = &form[(ft_check_flag(form, conv))];
		if ((ft_check_form(*form)) == 2)
			form = &form[(ft_check_width(form, conv, arg))];
		if ((ft_check_form(*form)) == 5)
		{
			form++;
			conv->type = 10;
		}
		if ((ft_check_form(*form)) == 3)
			form = &form[(ft_check_precision(form, conv, arg))];
		if ((ft_check_form(*form)) == 4)
			form = &form[(ft_check_type(form, conv))];
	}
	else
		return (NULL);
	return (form);
}

int	ft_printf(const char *format, ...)
{
	char			*form;
	va_list			arg;
	t_point			conv;

	ft_cln(&conv);
	if (!format)
		return (0);
	form = (char *)format;
	va_start(arg, format);
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			form = ft_printf2(form, &conv, arg);
			if (!form)
				return (ft_write("error config %%\n", 1));
			if (conv.type > 0)
				if ((ft_conv_flags(arg, &conv)) == 0)
					return (ft_write("error maloc %%\n", 1));
		}
		else
			ft_write(form++, 0);
	}
	va_end(arg);
	return (ft_write(form, -1));
}
