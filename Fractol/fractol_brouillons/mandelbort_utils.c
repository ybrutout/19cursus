/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:22:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 14:27:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include "include/mlx.h"

void	*change_mlx(int i, int a, int b)
{
	static t_mlx	*mlx;
	static t_alg	*alg;

	if (!mlx)
		mlx = init_struct(0);
	if (!alg)
		alg = init_struct(1);
	if (i == 1)
		return (mlx);
	if (i == 2)
		return (alg);
	if (i == 3)
	{
		alg->z_i = 0;
		alg->z_r = 0;
		alg->c_i = 0;
		alg->c_r = 0;
		alg->tmp = 0;
		alg->count = 0;
		alg->i = -1;
		alg->c_r = (long double)a / SCRN_W * 4 - 2.0;
		alg->c_i = (long double)b / SCRN_H * 4 - 2.0;
		return (alg);
	}
	return (NULL);
}
