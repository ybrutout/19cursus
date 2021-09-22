/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:45:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/22 13:40:02 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_settings(void)
{
	printf("------------------------------------------");
	printf("-------------------------------------------------------\n");
	printf("|\tThe fractal program, takes as parameter the ");
	printf("name of the desired fractal.\t\t|\n");
	printf("|\tThe valid parameters are : \t\t\t\t\t\t\t\t|\n");
	printf("|\t- Julia \t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t- Mandelbrot \t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\tIf you want to set up your own julia enter ");
	printf("the value of your real c as the second\t|\n");
	printf("|\targument and the value of your imaginary c ");
	printf("as the third argument.\t\t\t|\n");
	printf("|\texample :\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t-./fractol Julia 0.285 0.01\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\tThe number must be entered with its comma ");
	printf("also no it will be ignored\t\t\t|\n");
	printf("|\texample : 2.0\t\t\t\t\t\t\t\t\t\t|\n");
	printf("-----------------------------------------------");
	printf("--------------------------------------------------\n");
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
