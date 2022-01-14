/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/29 10:57:55 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(int message, t_philo *philo)
{
	pthread_mutex_lock(philo->arg->sec_died);
	ft_putnbr((get_current() - philo->arg->start) / 1000);
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
	pthread_mutex_unlock(philo->arg->sec_died);
}

long	get_current(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

void	ft_sleep(long ms, t_arg *arg)
{
	const long	time_start = get_current();

	if (ms <= 0)
		return ;
	while (get_current() - time_start < ms * 1000 && !arg->died)
		usleep(80);
}
