/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:55:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/31 14:14:55 by ybrutout         ###   ########.fr       */
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

int mouse_handler(int keycode, int x, int y, void *params)
{
	(void)keycode;
	(void)x;
	(void)y;
	t_fract	*fract;

	fract = (t_fract *)params;
	printf("%p\n", fract->nwindow);
	mandelbrot(keycode, fract);
	return (0);
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
		calc->min_im = calc->min_im - (calc->min_re * 0.05);
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 125)
	{
		calc->min_im = calc->min_im + (calc->min_re * 0.05);
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 124)
	{
		calc->min_re = calc->min_re - (calc->min_im * 0.05);
		printf("long double max == %Lf\n", calc->min_re - (calc->max_im - calc->min_im) * SCRN_H / SCRN_W);
		calc->max_re = calc->min_re - (calc->max_im - calc->min_im) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 123)
	{
		calc->min_re = calc->min_re + (calc->min_im * 0.05);
		calc->max_re = calc->min_re + (calc->max_im - calc->min_im) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 5 || keycode == 45)
	{
		calc->min_re = calc->min_re * 0.95;
		if (calc->max_re < 0)
			calc->max_re = calc->max_re * 1.05;
		else
			calc->max_re = calc->max_re * 0.95;
		calc->min_im = calc->min_im * 0.95;
		calc->max_im = calc->min_im + (calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
		calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
		calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
		calc->y = -1;
		calc->x = -1;
	}
	if (keycode == 4 || keycode == 46)
	{
		calc->min_re = calc->min_re * 1.05;
		if (calc->max_re < 0)
			calc->max_re = calc->max_re * 0.95;
		else
			calc->max_re = calc->max_re * 1.05;
		calc->min_im = calc->min_im * 1.05;
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
		mandelbrot_bis(&calc, &fract);
	}
	printf("max->re == %Lf\nmin->re == %Lf\nmax->im == %Lf\nmin->im == %Lf\n", calc->max_re, calc->min_re, calc->max_im, calc->min_im);
	printf("keyboard == %d\n", keycode);
	mlx_put_image_to_window(fract->mlx, fract->nwindow, fract->img->img, 0, 0);
	return (1);
}
