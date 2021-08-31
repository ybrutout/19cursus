/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:23:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/31 11:00:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	check_arg(int argc, char **argv)
{
	int			i;
	const char	*fractals_list[2] = {"Julia", "Mandelbrot"};

	i = 1;
	if (argc < 2)
		ft_error(ERROR_ARG_LESS);
	while (i <= 2)
	{
		if (ft_strncmp(argv[1], fractals_list[i - 1], ft_strlen(fractals_list[i - 1])) == 0)
			return (i);
		i++;
	}
	ft_error(ARG_ERROR);
	return (-1);
}

int		main(int argc, char **argv)
{
	int 	set;
	t_fract	*fract;

	set = check_arg(argc, argv);
	fract = malloc(sizeof(t_fract));
	if (!fract)
		ft_error(ERROR_MALLOC);
	init_fract(fract);
	if (set == 2)
		mandelbrot(1, fract);
	/*if (set == 1)
		julia();*/
	mlx_key_hook(fract->nwindow, mandelbrot, fract);
	mlx_mouse_hook(fract->nwindow, mouse_handler, fract);
	mlx_loop(fract->mlx);
	free(fract->img);
	free(fract);
}
