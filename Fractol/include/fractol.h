/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:56:14 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/19 12:02:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>

# define SCREEN_W 1090
# define SCREEN_H 1080
# define ITERATION 200
# define ERROR_MALLOC 10
# define ARG_ERROR 20
# define END 30

typedef struct	s_image
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*nwindow;
	t_img	*img;
}				t_mlx;

typedef struct	s_alg
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		tmp;
	int				i;
	int				count;
}				t_alg;

//utils
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	*init_struct(int i);
int		ft_error(int message, int nb_free, t_mlx *mlx, t_alg *alg);

//mandelbort_utils
void	*change_mlx(int i, int a, int b);

#endif
