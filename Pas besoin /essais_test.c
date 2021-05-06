/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:51:16 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/05 13:27:15 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_image {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_image;

typedef struct  s_ray {
    void	*mlx_ptr;
	void	*mlx_win;
	int		player_posx;
	int		player_posy;
	t_image	*img;
	t_image *sprite;
	t_image *north_text;
}               t_ray;

void            my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_player(t_image *img, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			my_mlx_pixel_put(img, x + j, y + i, 0x000000FF);
		}
	}
}

void	draw_rectangle(t_image *img)
{
	int		i;
	int		j;

	j = 30;
	while (j > 29 && j < 1051)
	{
		i = 30;
		while( i > 29 && i < 1891)
		{
			my_mlx_pixel_put(img, i, j, 0x00FF0000);
			i++;
		}
		j++;
	}
}

int	key_entry(int key, t_ray *ray)
{
	if (key == 126)
		ray->player_posx -= 5;
	if (key == 125)
		ray->player_posx += 5;
	if (key == 123)
		ray->player_posy -= 5;
	if (key == 124)
		ray->player_posy += 5;
	draw_rectangle(ray->img);
	draw_player(ray->img, ray->player_posy, ray->player_posx);
	mlx_put_image_to_window(ray->mlx_ptr, ray->mlx_win, ray->img->img, 0, 0);
	return (0);
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_image *new_image;
	t_ray *ray;
	int x;
	int y;

	x = 50;
	y = 50;
	ray = malloc(sizeof(t_ray));
	new_image = malloc(sizeof(t_image));
	mlx = mlx_init();
	if (mlx == (NULL))
		return (write(1, "erreur d'initiation\n", 20));
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Cub3D");
	new_image->img = mlx_new_image(mlx, 1920, 1080);
	new_image->addr = mlx_get_data_addr(new_image->img, &new_image->bits_per_pixel, &new_image->line_length, &new_image->endian);
	ray->img = new_image;
	ray->mlx_ptr = mlx;
	ray->mlx_win = mlx_win;
	ray->player_posx = 200;
	ray->player_posy = 200;
	mlx_hook(mlx_win, 2, 1<<0, key_entry, ray);
	mlx_loop (mlx);

}

/*if (argc == 1 || argc > 3)
		return(write(1, "error of arg\n", 13));*/
// C'est la securite pour voir qu'on a bien le bon nombre d'atgument
