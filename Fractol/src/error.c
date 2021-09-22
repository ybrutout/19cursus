/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:45:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/22 09:24:42 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_settings(void)
{
	printf("The fractal program, takes as parameter ");
	printf("the name of the desired fractal.\n");
	printf("The valid parameters are : \n");
	printf("\t- Julia\n\t- Mandelbrot\n");
}

void	free_clean(t_alg *calc, t_fract *fract, int message, int nb)
{
	if (nb > 0)
	{
		if (nb > 1)
		{
			if (nb > 2)
				free(calc);
			free(fract->img);
		}
		free(fract);
	}
	ft_error(message);
}

void	ft_error(int message)
{
	if (message == ERROR_ARG_LESS)
	{
		printf("Error : No argument detected\n");
		print_settings();
	}
	else if (message == ARG_ERROR)
	{
		printf("Error : Wrong argument\n");
		print_settings();
	}
	else if (message == ERROR_MALLOC)
	{
		printf("Error : Error with a malloc\n");
		exit(EXIT_FAILURE);
	}
	else if (message == END)
		printf("Goodbye !\n");
	exit(EXIT_SUCCESS);
}
