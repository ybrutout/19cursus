/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:37:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 13:32:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	printf_settings(void)
{
	write(1, "This program works with 4 mandatory arguments", 45);
	write(1, " and one optional argument:\n\n", 29);
	write(1, "\t1.the number of philosophers:\n", 31);
	write(1, "\t\tThis will also be equivalent to the number of forks.\n", 55);
	write(1, "\t2.time to die :\n", 17);
	write(1, "\t\tThis will be equivalent to the maximum", 40);
	write(1, " time it can take between two meals.\n", 37);
	write(1, "\t3.time to eat:\n", 16);
	write(1, "\t\tThis will be equal to the time it takes", 41);
	write(1, " each philosopher to eat.\n", 26);
	write(1, "\t4.Time to sleep:\n", 18);
	write(1, "\t\tThis will be equivalent to the time it takes each ", 52);
	write(1, "philosopher to sleep.\n", 22);
	write(1, "\t5.The number of meals:\n", 24);
	write(1, "\t\tThis will be equivalent to the number of meals each", 53);
	write(1, " philosopher must have eaten before the programme stops.\n\n", 58);
	write(1, "Notes: No mandatory argument can be negative or null.\n", 54);
}

void	ft_error(int message)
{
	if (message == BAD_ARG)
	{
		write(1, "Error : ARG\n\n", 13);
		printf_settings();
		exit(EXIT_SUCCESS);
	}
	if (message == ER_MAL)
	{
		write(1, "Error : BAD MALLOC\n", 19);
		exit(EXIT_FAILURE);
	}
	if (message == ER_MUTEX)
	{
		write(1, "Error : MUTEX\n", 14);
		exit(EXIT_FAILURE);
	}
}

void	free_clean(t_arg *arg, t_philo *philo, int nb, int message)
{
	if (nb > 0)
	{
		if (nb > 1)
		{
			if (nb > 2)
			{
				if (nb > 3)
				{
					pthread_mutex_destroy(arg->extra);
				}
				free(arg->extra);
			}
			free(arg->wait);
		}
		free(arg);
	}
	ft_error(message);
}
