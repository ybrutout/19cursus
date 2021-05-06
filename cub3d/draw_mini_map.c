/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:07:27 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/06 13:05:44 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void            my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_rectangle(t_ray *ray)
{
	int		x;
	int		y;

	y = 49;
	while (++y > 49 && y < 1031)
	{
		x = 49;
		while (++x > 49 && x < 1871)
			my_mlx_pixel_put(ray->nw_img, x, y, 0x00FF0000);
	}
}

void	draw_player(t_ray *ray, int	x, int y)
{
	int		i;
	int		j;

	j = -1;
	while( ++j < 10)
	{
		i = -1;
		while (++i < 10)
			my_mlx_pixel_put(ray->nw_img, x + i, y + j, 0x0000FF);
	}
}

int		key_hook(int keycode, t_ray *ray)
{
	draw_rectangle(ray);
	printf("keycode == %d\n", keycode);
	if (keycode == 126 && ray->player_posy > 50)
		ray->player_posy -= 5;
	else if (keycode == 125 && ray->player_posy < 1020)
		ray->player_posy += 5;
	else if (keycode == 123 && ray->player_posx > 50)
		ray->player_posx -= 5;
	else if (keycode == 124 && ray->player_posx < 1870)
		ray->player_posx += 5;
	draw_player(ray, ray->player_posx, ray->player_posy);
	mlx_put_image_to_window(ray->mlx_ptr, ray->mlx_win, ray->nw_img->img, 0, 0);
	return (1);
}
