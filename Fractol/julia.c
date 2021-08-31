/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:34:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/31 10:30:36 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

t_alg	*init_struct_jul(t_fract *fract)
{
	t_alg	*calc;

	calc = malloc(sizeof(t_alg));
	if (!calc)
	{
		free(fract->img);
		free(fract);
		ft_error(ERROR_MALLOC);
	}
	calc->min_re = -1.0;
	calc->max_re = 1.0;
	calc->min_im = -2.0;
	calc->max_im = calc->min_im + \
	(calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	calc->c_re = -0.8;
	calc->c_im = -0.156;
	calc->z_re = 0;
	calc->z_im = 0;
	calc->z_tmp = 0;
	calc->iteration = 0;
	calc->x = 0;
	calc->y = -1;
	return (calc);
}

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

int	essais(int keycode, t_alg *val)
{
	printf("keycode == %d\n", keycode);
	if (keycode == 600)
		printf("val == %Lf\n", val->x);
	return (1);
}

int	julia(void)
{
	t_alg	*calc;
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		ft_error(ERROR_MALLOC);
	init_fract(fract);
	calc = init_struct_jul(fract);
	while (++calc->y < SCRN_H - 1)
	{
		calc->x = -1;
		julia_bis(&calc, &fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->nwindow, fract->img->img, 0, 0);
	mlx_mouse_hook(fract->nwindow, essais, calc);
	mlx_loop(fract->mlx);
	free(calc);
	free(fract->img);
	free(fract);
	return (1);
}
