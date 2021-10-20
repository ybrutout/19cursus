/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 17:00:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_time(void *tmp)
{
	t_lst	*lst;

	lst = (t_lst *)tmp;
	ft_sleep(lst->philo->arg->tm_die / 2, lst->philo->arg);
	while (1)
	{
		lst = (t_lst *)tmp;
		while (lst)
		{
			if (((get_current() - lst->philo->last_eat)/1000) > lst->philo->arg->tm_die)
			{
				lst->philo->arg->died = 1;

				break;
			}
			else
					lst = lst->next;
		}
		if (lst->philo->arg->died == 1 || lst->philo->arg->end_meal == lst->philo->arg->nb_phil)
			break;
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
