/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:45:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 13:46:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	print_settings(void)
{
	printf("The fractal program, takes as parameter ");
	printf("the name of the desired fractal.\n");
	printf("The valid parameters are : \n");
	printf("\t- Julia\n\t- Mandelbrot\n");
}

void	ft_error(int message)
{
	if (message == ERROR_ARG_LESS)
	{
		printf("Error : No argument detected\n");
		print_settings();
		exit(EXIT_SUCCESS);
	}
	else if (message == ARG_ERROR)
	{
		printf("Error : Wrong argument\n");
		print_settings();
		exit(EXIT_SUCCESS);
	}
}
