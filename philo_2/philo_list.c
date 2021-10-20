/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:16:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 11:28:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_philo *philo, t_lst **first, t_arg	*arg, int i)
{
	static pthread_mutex_t	*last;

	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		return (0);
	if (pthread_mutex_init(philo->fork_right, NULL) != 0)
		return (1);
	if (i == 0)
		philo->fork_left = philo->fork_right;
	else if (i == arg->nb_phil)
	{
		philo->fork_left = last;
		(*first)->philo->fork_left = philo->fork_right;
	}
	else
		philo->fork_left = last;
	last = philo->fork_right;
	return (2);
}

static void	init_philo(t_philo *philo, t_lst *lst, int i, int mall)
{
	t_arg					*arg;
	static pthread_mutex_t	*last;
	int						ret;

	arg = init_arg(NULL);
	ret = init_fork(philo, &lst, arg, i);
	if (ret < 2)
	{
		if (ret == 0)
			free_clean(philo, lst, mall, ER_MAL);
		else
			free_clean(philo, lst, mall + 1, ER_MUTEX);
	}
	mall = mall + 2;
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
