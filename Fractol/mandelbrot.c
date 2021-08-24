/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:55:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 16:44:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include "include/mlx.h"

t_alg	*init_struct_man(t_fract *fract)
{
	t_alg	*calc;

	calc = malloc(sizeof(t_alg));
	if (!calc)
	{
		free(fract);
		ft_error(ERROR_MALLOC);
	}
	calc->min_re = -2.0;
	calc->max_re = 2.0;
	calc->min_im = -2.0;
	calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
	calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
	calc->c_re = 0;
	calc->c_im = 0;
	calc->z_re = 0;
	calc->z_im = 0;
	calc->z_tmp = 0;
	calc->iteration = 0;
	calc->x = 0;
	calc->y = 0;
	return (calc);
}

void	init_fract(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->img = malloc(sizeof(t_img));
	fract->nwindow = mlx_new_window(fract->mlx, SCRN_W, SCRN_H, "Fractol");
	fract->img->img = mlx_new_image(fract->mlx, SCRN_W, SCRN_H);
	fract->img->add = mlx_get_data_addr(fract->img->img, &(fract->img->bpp), &(fract->img->line_l), &(fract->img->endian));
}

int	mandelbrot(void)
{
	t_alg	*calc;
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		ft_error(ERROR_MALLOC);
	init_fract(fract);
	calc = init_struct_man(fract);
	while (calc->y < SCRN_H - 1)
	{
		calc->x = 0;
		calc->c_im = calc->max_im - (calc->y * calc->facteur_im);
		while (calc->x < SCRN_W - 1)
		{
			calc->c_re = calc->min_re + (calc->x * calc->facteur_re);
			calc->z_re = calc->c_re;
			calc->z_im = calc->c_im;
			calc->iteration = 0;
			while (calc->iteration < ITERATION)
			{
				calc->z_tmp = calc->z_re;
				calc->z_re = (calc->z_re * calc->z_re) - (calc->z_im * calc->z_im) + calc->c_re;
				calc->z_im = 2 * calc->z_tmp * calc->z_im + calc->c_im;
				if ((calc->z_re * calc->z_re) + (calc->z_im * calc->z_im) > 4)
					break;
				calc->iteration++;
			}
			if (calc->iteration == ITERATION)
				my_mlx_pixel_put(fract->img, calc->x, calc->y, 0);
			else
			{
				my_mlx_pixel_put(fract->img, calc->x, calc->y, 100 - calc->iteration);
			}
			calc->x++;
		}
		calc->y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->nwindow, fract->img->img, 0, 0);
	mlx_loop(fract->mlx);
	free(calc);
	return (0);
}
