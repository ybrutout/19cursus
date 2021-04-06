/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/04/06 11:43:08 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             ft_conv_flag(char *form, t_point *conv)
{
	int			j;

	j = 0;
	if(ft_check_type(*form) == 1)
	{
		if (*form == '-')
		{
			(*conv).minus = 1;
		}
		else if(*form == '0')
		{
			(*conv).zero = 1;
		}
		j++;
	}
	return (j);
}

int				ft_conv_width(char *form, t_point *conv)
{
	int			i;

	i = 0;
	while(*form >= '0' && *form <= '9')
	{
		(*conv).width = (*conv).width + (*form - 48);
		if (*form == '0')
			conv->width = conv->width * 10;
		i++;
		form++;
	}
	return (i);
}

int				ft_conv_precision(char *form, t_point *conv)
{
	int			i;
	i = 0;

	if (*form == '*')
	{
		(*conv).precision = 1;
		i++;
	}
	else if (*form == '.')
	{
		(*conv).dot = 1;
		i++;
	}
	return (i);
}
