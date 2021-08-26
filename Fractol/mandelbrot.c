/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:55:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/26 16:43:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

t_alg	*init_struct_man(t_fract *fract)
{
	t_alg	*calc;

	calc = malloc(sizeof(t_alg));
	if (!calc)
	{
		free (fract->img);
		free(fract);
		ft_error(ERROR_MALLOC);
	}
	calc->min_re = -2.5;
	calc->max_re = 1.3;
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
	calc->x = 0;
	calc->y = -1;
	return (calc);
}

void	mandelbrot_bis(t_alg **calc, t_fract **fract, int keycode)
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
		{
			if (keycode == 5)
				write(1, "hollacoucou\n", 12);
			my_mlx_pixel_put((*fract)->img, (*calc)->x, (*calc)->y, 0xE8C0DF + (300 * (*calc)->iteration));
		}
	}
}

int	mandelbrot(int keycode, t_fract *fract)
{
	static t_alg	*calc;
	int				i;//test

	if (!calc)
		calc = init_struct_man(fract);
	i = 0;
	if (keycode == 126)
	{
		calc->min_im = calc->min_im - 0.05;
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 125)
	{
		calc->min_im = calc->min_im + 0.05;
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 124)
	{
		calc->min_re = calc->min_re - 0.05;
		calc->max_re = calc->max_re - 0.05;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 123)
	{
		calc->min_re = calc->min_re + 0.05;
		calc->max_re = calc->max_re + 0.05;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 87)
	{
		calc->min_re = calc->min_re - 0.05;
		calc->max_re = calc->max_re + 0.05;
		calc->min_im = calc->min_im - 0.05;
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 84)
	{
		calc->min_re = calc->min_re + 0.05;
		calc->max_re = calc->max_re - 0.05;
		calc->min_im = calc->min_im + 0.05;
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	while (++calc->y < SCRN_H - 1)
	{
		calc->x = -1;
		calc->c_im = calc->max_im - (calc->y * calc->facteur_im);
		mandelbrot_bis(&calc, &fract, keycode);
	}
	write(1, "je suis la\n", 11);
	mlx_put_image_to_window(fract->mlx, fract->nwindow, fract->img->img, 0, 0);
	write(1, "je suis la\n", 11);
	printf("keycode == %d\n", keycode);
	return (1);
}
