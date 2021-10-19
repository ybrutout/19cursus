/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:16:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/19 14:34:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, t_lst *lst, int i, int mall)
{
	t_arg	*arg;

	arg = init_arg(NULL);
	philo->fork_left = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_left)
		free_clean(philo, lst, mall, ER_MAL);
	mall++;
	if (pthread_mutex_init(philo->fork_left, NULL))
		free_clean(philo, lst, mall, ER_MUTEX);
	mall++;
	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		free_clean(philo, lst, mall, ER_MAL);
	mall++;
	if (pthread_mutex_init(philo->fork_right, NULL))
		free_clean(philo, lst, mall, ER_MUTEX);
	mall++;
	philo->arg = arg;
	philo->last_eat = 0;
	philo->id = i;
}

static t_lst	*new_tmp_lst(t_philo *philo, t_lst *first, int mall)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (!tmp)
		free_clean(philo, first, mall, ER_MAL);
	tmp->philo = philo;
	tmp->next = 0;
	return (tmp);
}

t_lst	*init_lst(t_arg *arg)
{
	t_lst	*first;
	t_philo	*philo;
	t_lst	*tmp;
	int		i;
	int		mall;

	first = NULL;
	i = 0;
	mall = 3;
	while (++i <= arg->nb_phil)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			free_clean(philo, first, mall, ER_MAL);
		mall++;
		init_philo(philo, first, i, mall);
		mall = mall + 4;
		tmp = new_tmp_lst(philo, first, mall);
		mall++;
		first = ft_lst_add_back(first, tmp);
	}
	return (first);
}
