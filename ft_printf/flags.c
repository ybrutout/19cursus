/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/03/09 15:18:54 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char             *ft_conv_flag(char *form, va_list arg)
{
    t_point     conv;

    if (*form == '-')
	{
		conv.minus = 1;
	}
	else if(*form == '0')
	{
		conv.zero = 1;
	}
	else if (*form == '.')
	{
		conv.dot = 1;
	}
	else if (*form == '*')
	{
		conv.precision = 1;
	}
}