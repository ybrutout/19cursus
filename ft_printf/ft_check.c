/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:27:29 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/20 14:40:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(char *form, t_point *conv)
{
	if (*form == 'c')
		conv->type = 1;
	else if (*form == 'd' || *form == 'i')
		conv->type = 2;
	else if (*form == 's')
		conv->type = 3;
	else if (*form == 'p')
		conv->type = 4;
	else if (*form == 'u')
		conv->type = 5;
	else if (*form == 'x')
		conv->type = 6;
	else if (*form == 'X')
		conv->type = 7;
	return (1);
}

int	ft_check_form(char c)
{
	if (c == '-' || c == '0')
		return (1);
	if ((c > '0' && c <= '9') || c == '*')
		return (2);
	if (c == '.')
		return (3);
	if (c == 'd' || c == 'i' || c == 's' || c == 'p')
		return (4);
	if (c == 'c' || c == 'x' || c == 'X' || c == 'u')
		return (4);
	if (c == '%')
		return (5);
	return (0);
}

int	ft_check_flag(char *form, t_point *conv)
{
	int			j;

	j = 0;
	while (ft_check_form(*form) == 1)
	{
		if (*form == '-')
		{
			conv->minus = 1;
		}
		else if (*form == '0')
		{
			conv->zero = 1;
		}
		j++;
		form++;
	}
	return (j);
}

int	ft_check_width(char *form, t_point *conv, va_list arg)
{
	int			i;

	i = 0;
	if (*form == '*')
	{
		conv->width = va_arg(arg, int);
		if (conv->width < 0)
		{
			conv->width = conv->width * -1;
			conv->minus = 1;
		}
		i++;
	}
	else if (*form >= '0' && *form <= '9')
	{
		while (*form >= '0' && *form <= '9')
		{
			conv->width = (conv->width * 10) + (*form++ - 48);
			i++;
		}
	}
	return (i);
}

int	ft_check_precision(char *form, t_point *conv, va_list arg)
{
	int			i;

	i = 0;
	if (*form == '.')
	{
		conv->dot = 1;
		i++;
		form++;
		if (*form == '*')
		{
			conv->precision = va_arg(arg, int);
			i++;
		}
		while (*form >= '0' && *form <= '9')
		{
			conv->precision = (conv->precision * 10) + (*form++ - 48);
			i++;
		}
	}
	return (i);
}
