/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:37:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 14:49:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	printf_settings(void)
{
	write(1, "\nThis program works with 4 mandatory arguments", 46);
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
	write(1, "\t5.The number of meals: (optional)\n", 35);
	write(1, "\t\tThis will be equivalent to the number of meals each", 53);
	write(1, " philosopher must have eaten before the programme stops.\n\n", 58);
	write(1, "Notes: No mandatory argument can be negative or null.\n\n", 55);
}

int	ft_error(int message)
{
	if (message == ER_ARG)
		printf_settings();
	else if (message == ER_MAL)
		write(1, "Malloc Error\n", 13);
	else if (message == ER_MUTEX)
		write(1, "Mutex Error\n", 12);
	else if (message == THR)
		write(1, "Thread Error\n", 13);
	else if (message == END)
		return (0);
	return (1);
}

static int	free_lst(t_philo *philo, int nb)
{
	if (nb > 4)
	{
		if (nb > 5)
		{
			pthread_mutex_destroy(philo->fork_right);
			nb--;
		}
		free(philo->fork_right);
		nb--;
	}
	free(philo);
	nb--;
	return (nb);
}

static t_philo	*tmp_is(t_philo *philo, t_lst **lst, int message)
{
	t_philo	*tmp;
	t_lst	*tmp_lst;

	if (*lst)
	{
		tmp = (*lst)->philo;
		tmp_lst = (*lst)->next;
		free(*lst);
		*lst = tmp_lst;
	}
	else if (message != END)
		tmp = philo;
	else
		return (NULL);
	return (tmp);
}

int	free_clean(t_philo *philo, t_lst *lst, int nb, int message)
{
	t_arg	*arg;
	t_philo	*tmp;

	init_arg(NULL, &arg);
	if (nb > 0)
	{
		if (nb > 1)
		{
			if (nb > 2)
			{
				while (nb > 3)
				{
					tmp = tmp_is(philo, &lst, message);
					if (!tmp)
						break ;
					nb = free_lst(tmp, nb);
				}
				pthread_mutex_destroy(arg->sec_died);
			}
			free(arg->sec_died);
		}
		free(arg);
	}
	return (ft_error(message));
}
