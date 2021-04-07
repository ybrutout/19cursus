/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/04/07 17:27:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_flags(va_list arg, t_point *conv)
{
	char	*nw_str;

	if (conv->minus == 1)
	{
		conv->str = ft_conv_c(va_arg(arg, int));
		if (conv->width > 0)
		{
			nw_str = (char *)malloc(sizeof(char) * (conv->width) + 1);
			if (!nw_str)
				return (0);

		}
	}
}
