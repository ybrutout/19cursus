/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:42:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/19 11:14:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/fractol.h"

int	put_image(void)
{
	int	b;
	int	a;
	t_mlx		*mlx;
	t_alg		*alg;

	mlx = change_mlx(1, 0, 0);
	alg = change_mlx(2, 0, 0);
	b = -1;
	while (++b < SCREEN_H)
	{
		a = -1;
		while (++a < SCREEN_W)
		{
			alg = change_mlx(3, a, b);
			while (++alg->i < ITERATION)
			{
				alg->tmp = alg->z_r;
				alg->z_r = (pow(alg->z_r, 2)) - (pow(alg->z_i, 2)) + alg->c_r;
				alg->z_i = (2 * alg->z_i * alg->tmp) + alg->c_i;
				if ((alg->z_i * alg->z_i + alg->z_r * alg->z_r) > 4)
					break ;
				alg->count++;
			}
			if (alg->count == ITERATION)
				my_mlx_pixel_put(mlx->img, a, b, 0);
			else
				my_mlx_pixel_put(mlx->img, a, b, 98798798 + 1000 * alg->count);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->nwindow, mlx->img->img, 0, 0);
	mlx_loop(mlx);
	free(mlx->img);
	free(mlx);
	free(alg);
	return (1);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	put_image();
	return (0);
}
