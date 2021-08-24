/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:32:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 14:27:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include "include/mlx.h"


void	*change_mlx(int i, int a, int b)
{
	static t_mlx	*mlx;
	static t_alg	*alg;

	if (!mlx)
		mlx = init_struct(0);
	if (!alg)
		alg = init_struct(1);
	if (i == 1)
		return (mlx);
	if (i == 2)
		return (alg);
	if (i == 3)
	{
		alg->z_i = (long double)b / SCRN_H * 4 - 2.0;
		alg->z_r = (long double)a / SCRN_W * 4 - 2.0;
		alg->tmp = 0;
		alg->count = 0;
		alg->i = -1;
		alg->c_r = 0.285;
		alg->c_i = -0.01;
		return (alg);
	}
	return (NULL);
}

int	main(void)
{
	int	b;
	int	a;
	t_mlx		*mlx;
	t_alg		*alg;

	mlx = change_mlx(1, 0, 0);
	alg = change_mlx(2, 0, 0);
	b = -1;
	while (++b < SCRN_H)
	{
		a = -1;
		while (++a < SCRN_W)
		{
			alg = change_mlx(3, a, b);
			while (++alg->i < ITERATION)
			{
				alg->tmp = alg->z_r;
				alg->z_r = (pow(alg->z_r, 2)) - (pow(alg->z_i, 2)) + alg->c_r;
				alg->z_i = (2 * alg->z_i * alg->tmp) + alg->c_i;
				if (((pow(alg->z_i, 2)) + (pow(alg->z_r, 2))) > 4)
					break ;
				alg->count++;
			}
			if (alg->count == ITERATION)
				my_mlx_pixel_put(mlx->img, a, b, 0);
			else
				my_mlx_pixel_put(mlx->img, a, b, 14900208 - (3500 * alg->count));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->nwindow, mlx->img->img, 0, 0);
	mlx_loop(mlx);
	free(mlx->img);
	free(mlx);
	free(alg);
	return (1);
}
