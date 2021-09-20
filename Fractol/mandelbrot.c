/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:55:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 11:39:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	mandelbrot_bis(t_alg **calc, t_fract **fract)
{
	while (++(*calc)->x < SCRN_W - 1)
	{
		(*calc)->c_re = (*calc)->min_re + ((*calc)->x * (*calc)->facteur_re);
		(*calc)->z_re = (*calc)->c_re;
		(*calc)->z_im = (*calc)->c_im;
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
			my_mlx_pixel_put((*fract)->img, (*calc)->x, (*calc)->y,  0xE8C0DF + (-300 * (*calc)->iteration));
	}
}

int	mandelbrot(t_fract *fract, t_alg *calc)
{
	calc->y = -1;
	while (++calc->y < SCRN_H - 1)
	{
		calc->x = -1;
		calc->c_im = calc->max_im - (calc->y * calc->facteur_im);
		mandelbrot_bis(&calc, &fract);
	}
	printf("max->re == %Lf\nmin->re == %Lf\nmax->im == %Lf\nmin->im == %Lf\n", calc->max_re, calc->min_re, calc->max_im, calc->min_im);//test
	printf("facteur_re == %Lf\nfacteur_im == %Lf\n", calc->facteur_re, calc->facteur_im);//test
	mlx_put_image_to_window(fract->mlx, fract->nwindow, fract->img->img, 0, 0);
	return (1);
}
