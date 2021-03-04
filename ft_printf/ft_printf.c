/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:21 by mushu             #+#    #+#             */
/*   Updated: 2021/03/04 13:01:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	int				i;
	char			c;
	va_list			arg;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				write(1, "%", 1);
			else if (format[i] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
			}
			else if (format[i] == 'd')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	return (0);
}
