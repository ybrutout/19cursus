/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:21:09 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 15:55:39 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	maybe_is_finish(int message, t_philo *philo)
{
	pthread_mutex_lock(philo->arg->sec_died);
	if (philo->arg->died == 1)
		return (1);
	else if (philo->arg->end_meal == philo->arg->phill)
		return (1);
	else
		ft_write(message, philo);
	pthread_mutex_unlock(philo->arg->sec_died);
	return (0);
}

static int	ft_fork(pthread_mutex_t *fst, pthread_mutex_t *sec, t_philo *philo)
{
	pthread_mutex_lock(fst);
	if (maybe_is_finish(FORK, philo))
	{
		pthread_mutex_unlock(fst);
		return (1);
	}
	pthread_mutex_lock(sec);
	if (maybe_is_finish(FORK, philo))
	{
		pthread_mutex_unlock(fst);
		pthread_mutex_unlock(sec);
		return (1);
	}
	return (0);
}

static int	ft_hungry(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (ft_fork(philo->fork_left, philo->fork_right, philo))
			return (1);
		if (maybe_is_finish(EAT, philo))
		{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			return (1);
		}
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	else
	{
		if (ft_fork(philo->fork_right, philo->fork_left, philo))
			return (1);
		if (maybe_is_finish(EAT, philo))
			return (1);
		ft_sleep(philo->arg->tm_eat, philo->arg);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
	}
	return (0);
}

static int	ft_tired(t_philo *philo)
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
	if (philo->id % 2 && philo->arg->phill != 1)
		ft_sleep(philo->arg->tm_eat / 2, philo->arg);
	while (philo->arg->died != 1)
	{
		if (ft_hungry(philo))
			return (NULL);
		if (ft_tired(philo))
			return (NULL);
	}
	return (NULL);
}
