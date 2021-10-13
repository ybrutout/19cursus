/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:57:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/13 16:18:51 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_hungry(t_lst_philo *lst, t_philo *philo, t_arg *arg)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo->fork_right);
	ft_write(FORK, philo, lst, arg);
	pthread_mutex_lock(philo->fork_left);
	ft_write(FORK, philo, lst, arg);
	ft_write(EAT, philo, lst, arg);
	return (i);
}

void	*routine(void *lst)
{
	t_arg		*arg;
	t_lst_philo	*lst_philo;
	t_philo		*philo;
	int			ret;

	arg = init_arg(0, NULL);
	lst_philo = (t_lst_philo*)lst;
	philo = lst_philo->philo;
	philo->lst_eat = ft_actual_time(philo, lst, arg) - philo->start_tm;
	ret = 0;
	if (philo->id % 2 && arg->nb_philo % 2)
		ft_sleep(800, lst);
	while (arg->dead != 1 || ret == 1)
	{
		ret = ft_hungry(lst, philo, arg);

	}
	return (NULL);
}
