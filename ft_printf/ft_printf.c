/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:21 by mushu             #+#    #+#             */
/*   Updated: 2021/03/04 12:22:34 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	int				i;
	char 			c;
	va_list			arg;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = va_arg(arg, char);
				write(1, c, 1);
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	return(0);
}