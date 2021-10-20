/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:21:09 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 11:46:02 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(int message, t_philo *philo)
{
	pthread_mutex_lock(philo->arg->sec_died);
	ft_putnbr((get_current() - philo->arg->start)/1000);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	if (message == FORK)
		write(1, " taken a fork\n", 14);
	if (message == EAT)
		write(1, " is eating\n", 11);
	if (message == SLEEP)
		write(1, " is sleeping\n", 13);
	if (message == THINK)
		write(1, " is thinking\n", 13);
	if (message == DEAD)
		write(1, " died\n", 6);
	if (message == TEST)
		write(1, " ici\n", 5);
	pthread_mutex_unlock(philo->arg->sec_died);
}

void	ft_hungry(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->fork_right);
		pthread_mutex_lock(philo->fork_left);
		ft_write(FORK, philo);
		ft_write(FORK, philo);
		ft_write(EAT, philo);
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		pthread_mutex_lock(philo->fork_right);
		ft_write(FORK, philo);
		ft_write(FORK, philo);
		ft_write(EAT, philo);
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
}

void	ft_tired(t_philo *philo)
{
	ft_write(SLEEP, philo);
	ft_sleep(philo->arg->tm_sleep, philo->arg);
	ft_write(THINK, philo);
}

void	*routine(void *tmp)
{
	t_philo	*philo;
	t_lst	*lst;

	lst = tmp;
	philo = lst->philo;
	if (philo->id % 2 && philo->arg->nb_phil % 2)
	{
		ft_sleep(philo->arg->tm_eat / 2, philo->arg);
		ft_write(TEST, philo);
	}
	while (philo->arg->died != 1)
	{
		ft_hungry(philo);
		ft_tired(philo);
	}
	ft_write(TEST, philo);
	return (NULL);
}
