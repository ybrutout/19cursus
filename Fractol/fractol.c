/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:23:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/26 09:50:19 by ybrutout         ###   ########.fr       */
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

	set = check_arg(argc, argv);
	if (set == 2)
		mandelbrot();
	if (set == 1)
		julia();
}
