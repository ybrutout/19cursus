/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:47:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 14:33:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_fract(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->img = malloc(sizeof(t_img));
	if (!fract->img)
		free_clean(NULL, fract, ERROR_MALLOC, 1);
	fract->nwindow = mlx_new_window(fract->mlx, SCRN_W, SCRN_H, "Fractol");
	fract->img->img = mlx_new_image(fract->mlx, SCRN_W, SCRN_H);
	fract->img->add = mlx_get_data_addr(fract->img->img, \
	&(fract->img->bpp), &(fract->img->line_l), &(fract->img->endian));
}

void	init_struct_man(t_alg *calc)
{
	calc->min_re = -2.5;
	calc->max_re = 1.4;
	calc->min_im = -1.8;
	calc->max_im = calc->min_im + \
	(calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
	calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
	calc->c_re = 0;
	calc->c_im = 0;
	calc->z_re = 0;
	calc->z_im = 0;
	calc->z_tmp = 0;
	calc->iteration = 0;
	calc->id = 2;
}

void	init_struct_julia(t_alg *calc)
{
	calc->min_re = -2.0;
	calc->max_re = 2.0;
	calc->min_im = -1.5;
	calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	calc->c_re = -0.4;
	calc->c_im = 0.6;
	calc->z_re = 0;
	calc->z_im = 0;
	calc->z_tmp = 0;
	calc->iteration = 0;
	calc->id = 1;
	calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
	calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
}

t_alg	*find_the_calc(t_fract *fract, int set, int argc, char **argv)
{
	static t_alg	*calc;
	long double		c_re;
	long double		c_im;

	if (!calc)
	{
		calc = malloc(sizeof(t_alg));
		if (!calc)
			free_clean(NULL, fract, ERROR_MALLOC, 2);
		if (set == 2)
			init_struct_man(calc);
		else if (set == 1)
			init_struct_julia(calc);
	}
	return (calc);
}
