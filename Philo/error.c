/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:06 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 12:00:01 by ybrutout         ###   ########.fr       */
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
	t_philo		*tmp;
	t_lst_philo	*tmp_lst;

	if (nb >= 1)
	{
		while (nb >= 2)
		{
			if (first)
				tmp = first->philo;
			else
				tmp = philo;
			if (nb >= 3)
			{
				if (nb >= 4)
				{
					tmp_lst = first->next;
					free(first);
					first = tmp_lst;
					nb--;
				}
				pthread_mutex_destroy(tmp->fork_right);
				nb--;
			}
			free(tmp);
			nb--;
		}
		free(arg);
		nb--;
	}
	ft_message(message);
}
