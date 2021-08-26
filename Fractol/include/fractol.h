/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:56:14 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/26 09:53:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

// MACCRO

# define SCRN_W 1190
# define SCRN_H 1080
# define ITERATION 250

# define ERROR_MALLOC 10
# define ARG_ERROR 20
# define ERROR_ARG_LESS 30
# define END 100

//STRUCTURE

typedef struct	s_image
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_l;
	int		endian;
}				t_img;

typedef struct	s_fractal
{
	void	*mlx;
	void	*nwindow;
	t_img	*img;
}				t_fract;

typedef struct	s_alg
{
	long double	min_re;
	long double	max_re;
	long double	min_im;
	long double	max_im;
	long double	facteur_re;
	long double	facteur_im;
	long double	c_re;
	long double	c_im;
	long double	z_re;
	long double	z_im;
	long double z_tmp;
	int			iteration;
	int			x;
	int			y;
}				t_alg;

//FRACTOL
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

//LIBFT
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
int			ft_strlen(const char *s);

//ERROR
void		print_settings(void);
void		ft_error(int message);

//UTILS
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
//long double	ft_pow(long double nb, int exposant);
void		init_fract(t_fract *fract);

//MANDELBROT
t_alg		*init_struct_man(t_fract *fract);
void		init_fract(t_fract *fract);
int			mandelbrot(void);

//JULIA
int			julia(void);
#endif
