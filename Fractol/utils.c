/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:47:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/31 10:30:46 by ybrutout         ###   ########.fr       */
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
	{
		free(fract);
		ft_error(ERROR_MALLOC);
	}
	fract->nwindow = mlx_new_window(fract->mlx, SCRN_W, SCRN_H, "Fractol");
	fract->img->img = mlx_new_image(fract->mlx, SCRN_W, SCRN_H);
	fract->img->add = mlx_get_data_addr(fract->img->img, \
	&(fract->img->bpp), &(fract->img->line_l), &(fract->img->endian));
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
