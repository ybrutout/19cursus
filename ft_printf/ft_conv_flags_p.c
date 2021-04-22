/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:35:00 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/22 16:27:33 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_flags_p_minus(unsigned long long int nw_ad, t_point *conv)
{

}

static void	ft_conv_flags_p_zero(unsigned long long int nw_ad, t_point *conv)
{

}

static void	ft_conv_flags_p_width(unsigned long long int nw_ad, t_point *conv)
{

}

static void	ft_conv_flags_p_dot(unsigned long long int nw_ad, t_point *conv)
{

}

void	ft_conv_flags_p(void *adress, t_point *conv)
{
	unsigned long long int	nw_ad;

	nw_ad = (unsigned long long int) adress;
	conv->size = ft_strlen_nb(nw_ad, 16);
	if (conv->dot = 1)
		ft_conv_flags_p_dot(nw_ad, conv);
	if (conv->width > 0)
		;
	else
	{
		ft_0x();
		ft_putnbr(nw_ad, 16, "0123456789abcdef");
	}
}
