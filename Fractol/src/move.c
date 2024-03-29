/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:12:34 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/22 13:05:49 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	frame(t_fract *fract)
{
	t_alg	*calc;

	calc = find_the_calc(fract, 0, 0, NULL);
	if (calc->id == 2)
		mandelbrot(fract, calc);
	else if (calc->id == 1)
		julia(fract, calc);
	return (1);
}

void	move_key_bis(int keycode, t_alg *calc)
{
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 126)
			calc->min_im = calc->min_im + (30 * calc->facteur_im);
		else
			calc->min_im = calc->min_im - (30 * calc->facteur_im);
		calc->max_im = calc->min_im + \
		(calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	}
	if (keycode == 123)
	{
		calc->min_re = calc->min_re - (30 * calc->facteur_re);
		calc->max_re = calc->max_re - (30 * calc->facteur_re);
	}
	if (keycode == 124)
	{
		calc->min_re = calc->min_re + (30 * calc->facteur_re);
		calc->max_re = calc->max_re + (30 * calc->facteur_re);
	}
	calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
	calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
}

int	move_key(int keycode, t_fract *fract)
{
	t_alg	*calc;

	calc = find_the_calc(fract, 0, 0, NULL);
	if (keycode >= 123 && keycode <= 126)
		move_key_bis(keycode, calc);
	if (keycode == 53)
		free_clean(calc, fract, END, 3);
	if (keycode == 45)
		mouse_handler(5, 0, 0, fract);
	if (keycode == 46)
		mouse_handler(4, 0, 0, fract);
	return (1);
}

int	mouse_handler(int keycode, int x, int y, t_fract *fract)
{
	t_alg	*calc;

	(void)x;
	(void)y;
	calc = find_the_calc(fract, 0, 0, NULL);
	if (keycode == 5)
	{
		calc->min_re = calc->min_re + (ZOOM * calc->facteur_re);
		calc->max_re = calc->max_re - (ZOOM * calc->facteur_re);
		calc->min_im = calc->min_im + (ZOOM * calc->facteur_im);
		calc->max_im = calc->min_im + \
		(calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	}
	if (keycode == 4)
	{
		calc->min_re = calc->min_re - (ZOOM * calc->facteur_re);
		calc->max_re = calc->max_re + (ZOOM * calc->facteur_re);
		calc->min_im = calc->min_im - (ZOOM * calc->facteur_im);
		calc->max_im = calc->min_im + \
		(calc->max_re - calc->min_re) * SCRN_H / SCRN_W;
	}
	calc->facteur_re = (calc->max_re - calc->min_re) / (SCRN_W - 1);
	calc->facteur_im = (calc->max_im - calc->min_im) / (SCRN_H - 1);
	return (1);
}

int	close_x(t_fract *fract)
{
	t_alg	*calc;

	calc = find_the_calc(NULL, 0, 0, NULL);
	free_clean(calc, fract, END, 3);
	return (1);
}
