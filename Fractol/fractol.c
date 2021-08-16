/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:15 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 15:45:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(void)
{
	void	*mlx;
	void	*new_window;

	mlx = mlx_init();
	new_window = mlx_new_window(mlx, 1920, 1080, "Coucou toi !");
	mlx_loop(mlx);

}
