/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:57:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 11:09:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	it_s_my_fork(t_philo *philo, t_lst_philo *lst, t_arg *arg)
{
	if (philo->id % 2)
	{
		if (pthread_mutex_lock(philo->fork_right) != 0)
		{
			write(1, "j'ai un probleme de fourchette droite\n", 38);//a enlever
			exit(EXIT_FAILURE);//a enlever
			return (0);
		}
		ft_write(FORK, philo, lst, arg);
		pthread_mutex_lock(philo->fork_left);
		ft_write(FORK, philo, lst, arg);
	}
	else
	{
		if (pthread_mutex_lock(philo->fork_left) != 0)
		{
			write(1, "j'ai un probleme de fourchette gauche\n", 38);//a enlever
			exit(EXIT_FAILURE);//a enlever
			return (0);
		}
		ft_write(FORK, philo, lst, arg);
		pthread_mutex_lock(philo->fork_right);
		ft_write(FORK, philo, lst, arg);
	}
	return (1);
}

int	ft_hungry(t_lst_philo *lst, t_philo *philo, t_arg *arg)
{
	if (it_s_my_fork(philo, lst, arg) == 0)
		return (0);
	ft_write(EAT, philo, lst, arg);
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

	arg = init_arg(0, NULL);
	lst_philo = (t_lst_philo*)lst;
	philo = lst_philo->philo;
	while (*philo->extra == 1)
		usleep(80);
	philo->start_tm = ft_actual_time(philo, lst, arg);
	philo->lst_eat = ft_actual_time(philo, lst, arg) - philo->start_tm;
	if (philo->id % 2 && arg->nb_philo % 2)
		ft_sleep(800, lst);
	if (!(philo->id % 2) && !(arg->nb_philo % 2))
		ft_sleep(arg->tm_eat * 2, lst);
	while (arg->dead != 1)
	{
		if (ft_hungry(lst, philo, arg) == 0)
			break ;
		if (ft_other(lst, philo, arg) == 0)
			break;
	}
	return (NULL);
}
