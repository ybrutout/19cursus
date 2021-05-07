/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:28:12 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 11:58:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	int		player_posx;
	int		player_posy;
	t_image *nw_img;
}				t_ray;

typedef	struct	s_struct
{
	int		resol_x;
	int		resol_y;
}				t_struc;


int		key_hook(int keycode, t_ray *ray);
int		check_arg(int argc, char **argv);
int		ft_parsing(int argc, char **argv);
void	draw_player(t_ray *ray, int	x, int y);
void	draw_rectangle(t_ray *ray);
void    my_mlx_pixel_put(t_image *data, int x, int y, int color);

#endif
