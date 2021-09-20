/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:34:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 11:43:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	julia_bis(t_alg **calc, t_fract **fract)
{
	while (++(*calc)->x < SCRN_W - 1)
	{
		(*calc)->z_re = (long double)(*calc)->x / SCRN_W * 4 - 2.0;
		(*calc)->z_im = (long double)(*calc)->y / SCRN_H * 4 - 2.0;
		(*calc)->iteration = 0;
		while ((*calc)->iteration < ITERATION)
		{
			(*calc)->z_tmp = (*calc)->z_re;
			(*calc)->z_re = ((*calc)->z_re * (*calc)->z_re) - \
			((*calc)->z_im * (*calc)->z_im) + (*calc)->c_re;
			(*calc)->z_im = 2 * (*calc)->z_tmp * (*calc)->z_im + (*calc)->c_im;
			if (((*calc)->z_re * (*calc)->z_re) + \
			((*calc)->z_im * (*calc)->z_im) > 4)
				break ;
			(*calc)->iteration++;
		}
		if ((*calc)->iteration == ITERATION)
			my_mlx_pixel_put((*fract)->img, (*calc)->x, (*calc)->y, 0);
		else
			my_mlx_pixel_put((*fract)->img, (*calc)->x, (*calc)->y, \
			0xE8C0DF + (300000 * ((*calc)->iteration) / ITERATION));
	}
}

int	julia(t_fract *fract, t_alg *calc)
{
	calc->y = -1;
	while (++calc->y < SCRN_H - 1)
	{
		calc->x = -1;
		julia_bis(&calc, &fract);
	}
	return (1);
}
