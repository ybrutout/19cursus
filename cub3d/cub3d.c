/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:17:22 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 11:58:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_ray	*ray;

	if (ft_parsing(argc, argv) != 1)
		return(0);
	ray = malloc(sizeof(t_ray));
	ray->nw_img = malloc(sizeof(t_image));
	ray->mlx_ptr = mlx_init();
	if (ray->mlx_ptr == (NULL))
		return (write(1, "erreur d'initiation\n", 20));
	ray->mlx_win = mlx_new_window(ray->mlx_ptr, 1920, 1080, "Cub3D");
	ray->nw_img->img = mlx_new_image(ray->mlx_ptr, 1920, 1080);
	ray->nw_img->addr = mlx_get_data_addr(ray->nw_img->img, &ray->nw_img->bits_per_pixel, &ray->nw_img->line_length, &ray->nw_img->endian);
	ray->player_posx = 100;
	ray->player_posy = 100;
	mlx_hook(ray->mlx_win, 2, 1L<<0, key_hook, ray);
	mlx_loop (ray->mlx_ptr);
}
