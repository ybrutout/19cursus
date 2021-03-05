/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:21 by mushu             #+#    #+#             */
/*   Updated: 2021/03/04 18:27:42 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_write(char *str)
{
	int				i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

}

int					ft_printf(const char *format, ...)
{
	int				i;
	char			*form;
	va_list			arg;

	form = (char *)format;
	va_start(arg, format);
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '%')
			{
				ft_write(form);
				form++;
			}
			else
			{
				if (!(i = ft_conv_type(form, arg)))
					return (0);
				form++;
			}
		}
		else
		{
			write(1, form, 1);
			form++;
		}
	}
	va_end(arg);
	return (0);
}
