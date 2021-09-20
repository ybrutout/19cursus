/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:47:03 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 12:57:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	frame(t_fract *fract)
{
	t_alg	*calc;

	calc = find_the_calc(fract, 0);
	if (calc->id == 2)
		mandelbrot(fract, calc);
	else if (calc->id == 1)
		julia(fract, calc);
	return (1);
}
