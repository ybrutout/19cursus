/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/03/26 16:39:34 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             ft_conv_flag(char *form)
{
    t_point     conv;
	int			j;

	j = 0;
	if(ft_check_type(*form) == 1)
	{
		if (*form == '-')
		{
			conv.minus = 1;
		}
		else if(*form == '0')
		{
			conv.zero = 1;
		}
		j++;
	}
	return (j);
}

int				ft_conv_width(char *form)
{
	int			i;

	i = 0;
	while(*form >= '0' && *form <= '9')
		i++;
	return (i);
}