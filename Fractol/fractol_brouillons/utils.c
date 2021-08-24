/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:55:01 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 15:06:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	*init_struct(int i)
{
	t_mlx	*mlx;
	t_alg	*alg;

	if (i == 0)
	{
		mlx = malloc(sizeof(t_mlx));
		if (!mlx)
			ft_error(ERROR_MALLOC, 0, NULL, NULL);
		mlx->mlx = mlx_init();
		mlx->nwindow = mlx_new_window(mlx->mlx, SCRN_W, SCRN_H, "Fract_ol");
		mlx->img = malloc(sizeof(t_img));
		if (!mlx->img)
		{
			free(mlx);
			return (0);
		}
		mlx->img->img = mlx_new_image(mlx->mlx, SCRN_W, SCRN_H);
		mlx->img->add = mlx_get_data_addr(mlx->img->img, &mlx->img->bpp, &mlx->img->line_l, &mlx->img->endian);
		return (mlx);
	}
	if (i == 1)
	{
		alg = malloc(sizeof(t_alg));
		if (!alg)
			ft_error(ERROR_MALLOC, 3, mlx, NULL);
		alg->z_i = 0;
		alg->z_r = 0;
		alg->c_i = 0;
		alg->c_r = 0;
		alg->tmp = 0;
		alg->i = -1;
		alg->count = 0;
		return (alg);
	}
	return (NULL);
}

int		ft_error(int message, int nb_free, t_mlx *mlx, t_alg *alg)
{
	if (message == ARG_ERROR)
	{
		write(1, "ARG_AVALAIBLE :\n- Mandelbrot\n- Julia\n", 37);
		exit(EXIT_SUCCESS);
	}
	if (nb_free >= 1)
		free(mlx);
	if (nb_free >= 2)
		free(mlx->img);
	if (nb_free == 3)
		free(alg);
	if (message == ERROR_MALLOC)
	{
		write(1, "Error - Malloc\n", 15);
		exit(EXIT_FAILURE);
	}
	else if (message == END)
		exit(EXIT_SUCCESS);
	return (0);
}
