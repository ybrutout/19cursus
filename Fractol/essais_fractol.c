/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/19 11:11:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/fractol.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(void)
{
	void	*mlx;
	t_img	img;
	void	*new_window;
	int		max_applied;
	int		a, b, i;//tests
	long double	new_a, new_b;//test
	int		count;//test

	mlx = mlx_init();
	max_applied = 30;
	new_window = mlx_new_window(mlx, SCREEN_W, SCREEN_H, "Hey");
	img.img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img.add = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	b = -1;
	while (++b < SCREEN_H)
	{
		a = -1;
		while (++a < SCREEN_W)
		{
			i = -1;
			count = 0;
			new_a = (long double)a / SCREEN_W * 2.0 - 2;
			new_b = (long double)b / SCREEN_H * 2.0 - 2;
			while (++i < max_applied)
			{
				new_a = pow(new_a, 2);
				new_b = pow(new_b, 2);
				if (new_a * new_b > 2)
					break;
				count++;
			}
			my_mlx_pixel_put(&img, a, b, 10000 * count);
		}
	}
	mlx_put_image_to_window(mlx, new_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
