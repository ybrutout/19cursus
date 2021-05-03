/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:07:27 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_image
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_image;

typedef struct	s_ray
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image *nw_img;
}				t_ray;


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
	printf("%d\n", keycode);
}

int	main()
{
	t_ray	*ray;
	ray = malloc(sizeof(t_ray));
	ray->nw_img = malloc(sizeof(t_image));
	ray->mlx_ptr = mlx_init();
	if (ray->mlx_ptr == (NULL))
		return (write(1, "erreur d'initiation\n", 20));
	ray->mlx_win = mlx_new_window(ray->mlx_ptr, 1920, 1080, "Cub3D");
	ray->nw_img->img = mlx_new_image(ray->mlx_ptr, 1920, 1080);
	ray->nw_img->addr = mlx_get_data_addr(ray->nw_img->img, &ray->nw_img->bits_per_pixel, &ray->nw_img->line_length, &ray->nw_img->endian);
	mlx_hook(ray->mlx_win, 2, 1L<<0, key_hook, ray);
	mlx_hook(ray->mlx_win, 17, 1L<<17, exit, NULL);
	mlx_loop (ray->mlx_ptr);
}
