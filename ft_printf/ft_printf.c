/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:21 by mushu             #+#    #+#             */
/*   Updated: 2021/03/08 09:45:32 by mushu            ###   ########.fr       */
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

int					ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
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
				ft_write(form, 2);
				form++;
			}
			else if(*form)
			{
				if (!(i = ft_conv_type(form, arg)))
					return (0);
				form++;
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
