/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 14:58:03 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(int message, t_philo *philo)
{
	ft_putnbr((get_current() - philo->arg->start) / 1000);
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
}

void	*routine_time(void *tmp)
{
	t_lst	*lst;
	t_arg	*arg;

	lst = (t_lst *)tmp;
	arg = lst->philo->arg;
	ft_sleep(lst->philo->arg->tm_die / 2, lst->philo->arg);
	while (1)
	{
		lst = (t_lst *)tmp;
		while (lst)
		{
			if (((get_current() - lst->philo->last_eat) / 1000) \
			> lst->philo->arg->tm_die)
			{
				lst->philo->arg->died = 1;
				ft_write(DEAD, lst->philo);
				break ;
			}
			else
				lst = lst->next;
		}
		if (arg->died == 1 || arg->end_meal == arg->phill)
			break ;
	}
	return (NULL);
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
