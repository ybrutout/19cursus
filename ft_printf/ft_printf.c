/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:21 by mushu             #+#    #+#             */
/*   Updated: 2021/03/12 18:13:30 by yannahbruto      ###   ########.fr       */
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
	if (c == '-' || ( c >= '0' || c <= '9'))
		return (1);
	if (c == 'd' || c == 'i' || c == 's' || c == 'p' || c == 'c' || c == 'x' || c == 'X')
		return (2);

}

int					ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
	int 			type; 
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
			else
			{
				if ((type = ft_check_type(&form)) == 1)
				{
					if (i = ft_conv_flag(*form, arg))
						return (0);
					form == &form[i];
				}
				if((type = ft_check_type(&form)) == 2)
				{
					if (!(i = ft_conv_type(form, arg)))
						return (0);
					form == &form[i];
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
