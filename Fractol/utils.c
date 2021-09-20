/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:47:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 12:49:51 by ybrutout         ###   ########.fr       */
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
	calc->id = 1;
}

t_alg	*find_the_calc(t_fract *fract, int set)
{
	static t_alg	*calc;

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

/*long double	ft_pow(long double nb, int exposant)
{
	int	i;
	long double	value;

	i = 0;
	value = 1;
	while (i < exposant)
	{
		value = value * nb;
		i++;
	}
	return (value);
}*/// pas besoin pour le moment a voir
