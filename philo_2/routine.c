/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:21:09 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 14:35:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		maybe_is_finish(int message, t_philo *philo)
{
	pthread_mutex_lock(philo->arg->sec_died);
	if (philo->arg->died == 1)
	{
		pthread_mutex_unlock(philo->arg->sec_died);
		return (1);
	}
	else if (philo->arg->end_meal == philo->arg->nb_phil)
	{
		pthread_mutex_unlock(philo->arg->sec_died);
		return (1);
	}
	else if (((get_current() - philo->last_eat)/1000) > philo->arg->tm_die)
	{
		philo->arg->died = 1;
		ft_write(DEAD, philo);
		pthread_mutex_unlock(philo->arg->sec_died);
		return (1);
	}
	else
		ft_write(message, philo);
	pthread_mutex_unlock(philo->arg->sec_died);
	return (0);
}

void	ft_write(int message, t_philo *philo)
{
	ft_putnbr((get_current() - philo->arg->start)/1000);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	if (message == FORK)
		write(1, " taken a fork\n", 14);
	if (message == EAT)
	{
		write(1, " is eating\n", 11);
		philo->meal++;
		philo->last_eat = get_current();
		if (philo->meal == philo->arg->nb_meal)
			philo->arg->end_meal++;
	}
	if (message == SLEEP)
		write(1, " is sleeping\n", 13);
	if (message == THINK)
		write(1, " is thinking\n", 13);
	if (message == DEAD)
		write(1, " died\n", 6);
	if (message == TEST)
		write(1, " ici\n", 5);
}

int	ft_hungry(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->fork_left);
		if (maybe_is_finish(FORK, philo))
			return (1);
		pthread_mutex_lock(philo->fork_right);
		if (maybe_is_finish(FORK, philo))
			return (1);
		if (maybe_is_finish(EAT, philo))
			return (1);
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		if (maybe_is_finish(FORK, philo))
			return (1);
		pthread_mutex_lock(philo->fork_left);
		if (maybe_is_finish(FORK, philo))
			return (1);
		if (maybe_is_finish(EAT, philo))
			return (1);
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
	}
	return (0);
}

int	ft_tired(t_philo *philo)
{
	if (maybe_is_finish(SLEEP, philo))
		return (1);
	ft_sleep(philo->arg->tm_sleep, philo->arg);
	if (maybe_is_finish(THINK, philo))
		return (1);
	return (0);
}

void	*routine(void *tmp)
{
	t_philo	*philo;
	t_lst	*lst;

	lst = tmp;
	philo = lst->philo;
	if (philo->id % 2 && philo->arg->nb_phil % 2)
		ft_sleep(philo->arg->tm_eat / 2, philo->arg);
	while (philo->arg->died != 1)
	{
		if (ft_hungry(philo))
			return (NULL);
		if (ft_tired(philo))
			return(NULL);
	}
	return (NULL);
}
