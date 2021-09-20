/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:56:14 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 15:12:24 by ybrutout         ###   ########.fr       */
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


/************/
/*	MACRO	*/
/************/

# define SCRN_W 512
# define SCRN_H 360
# define ITERATION 250

# define ERROR_MALLOC 10
# define ARG_ERROR 20
# define ERROR_ARG_LESS 30
# define END 100
# define ZOOM 20
# define MOVE 10

/****************/
/*	STRUCTURE	*/
/****************/

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
	int			id;
	long double	arg_cre;
	long double	arg_cim;
}				t_alg;



/****************/
/*	FONCTION	*/
/****************/

//LIBFT
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
int			ft_strlen(const char *s);
long double	ft_atoi(char *str);

//ERROR
void		free_clean(t_alg *calc, t_fract *fract, int message, int nb);
void		print_settings(void);
void		ft_error(int message);

//UTILS
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		init_fract(t_fract *fract);
void		init_struct_man(t_alg *calc);
void		init_struct_julia(t_alg *calc, long double c_re, long double c_im);
t_alg		*find_the_calc(t_fract *fract, int set, int argc, char **argv);

//MANDELBROT
int			mandelbrot(t_fract *fract, t_alg *calc);

//JULIA
int			julia(t_fract *fract, t_alg *calc);

//MOVE
int			move_key(int keycode, t_fract *fract);
int 		mouse_handler(int keycode, int x, int y, t_fract *fract);
int			frame(t_fract *fract);

#endif
