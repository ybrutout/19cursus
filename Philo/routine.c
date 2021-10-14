/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:57:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 09:42:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_hungry(t_lst_philo *lst, t_philo *philo, t_arg *arg)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	if (ft_write(FORK, philo, lst, arg) == 0)
		return (0);
	if (ft_write(FORK, philo, lst, arg) == 0)
		return (0);
	if (ft_write(EAT, philo, lst, arg) == 0)
		return (0);
	ft_sleep(arg->tm_eat, lst);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (1);
}

int	ft_other(t_lst_philo *lst, t_philo *philo, t_arg *arg)
{
	if (ft_write(SLEEP, philo, lst, arg) == 0)
		return (0);
	ft_sleep(arg->tm_sleep, lst);
	if (ft_write(THINK, philo, lst, arg) == 0)
		return (0);
	return (1);
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
	philo->start_tm = ft_actual_time(philo, lst, arg);
	philo->lst_eat = ft_actual_time(philo, lst, arg) - philo->start_tm;
	ret = 0;
	if (philo->id % 2 && arg->nb_philo % 2)
		ft_sleep(800, lst);
	if (!(philo->id % 2) && !(arg->nb_philo % 2))
		ft_sleep(arg->tm_eat, lst);
	while (arg->dead != 1)
	{
		if (ft_hungry(lst, philo, arg) == 0)
			break ;
		if (ft_other(lst, philo, arg) == 0)
			break;
	}
	return (NULL);
}
