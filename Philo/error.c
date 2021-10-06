/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:06 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 09:52:05 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_the_good_option(void)
{
	;
}

void	ft_message(int message)
{
	if (message == ER_MALLOC)
	{
		write(1, "Error : Malloc\n", 15);
		exit(EXIT_FAILURE);
	}
	else if (message == ER_ARG)
	{
		write(1, "Error : Wrong argument or not enough argument\n", 45);
		ft_write_the_good_option();
		exit(EXIT_SUCCESS);
	}
}

void	clean_free(t_arg *arg, t_lst_philo *first, t_philo *philo, int nb, int message)
{
	t_lst_philo	*tmp;

	if (nb >= 1)
	{
		if (nb >= 4)
		{
			while (nb > 1)
			{
				
			}
		}
		else if (nb == 2 || nb == 3)
		{
			if (nb >= 2)
			{
				if (nb == 3)
					pthread_mutex_destroy(philo->fork_right);
				free(philo);
			}
		}
		free(arg);
	}
	ft_message(message);
}
