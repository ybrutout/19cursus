/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:16:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 14:22:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_philo *philo, t_lst **first, t_arg	*arg, int i)
{
	static pthread_mutex_t	*last;

	if (!last)
		last = NULL;
	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		return (0);
	if (pthread_mutex_init(philo->fork_right, NULL) != 0)
		return (1);
	if (i == 1)
		philo->fork_left = philo->fork_right;
	else if (i == arg->phill)
	{
		philo->fork_left = last;
		(*first)->philo->fork_left = philo->fork_right;
	}
	else
		philo->fork_left = last;
	last = philo->fork_right;
	return (2);
}

static int	init_philo(t_philo *philo, t_lst *lst, int i, int mall)
{
	t_arg					*arg;
	int						ret;

	init_arg(NULL, &arg);
	ret = init_fork(philo, &lst, arg, i);
	if (ret < 2)
	{
		if (ret == 0)
			return (free_clean(philo, lst, mall, ER_MAL));
		else
			return (free_clean(philo, lst, mall + 1, ER_MUTEX));
	}
	philo->arg = arg;
	philo->last_eat = get_current();
	philo->id = i;
	philo->meal = 0;
	return (0);
}

static int	new_tmp_lst(t_philo *philo, t_lst *first, int mall, t_lst **lst)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (!tmp)
		return (free_clean(philo, first, mall, ER_MAL));
	tmp->philo = philo;
	tmp->next = 0;
	*lst = tmp;
	return (0);
}

static int	mall_phil(t_philo **philo, t_lst *first, int mall)
{
	*philo = malloc(sizeof(t_philo));
	if (!*philo)
		return (free_clean(*philo, first, mall, ER_MAL));
	return (0);
}

int	init_lst(t_arg *arg, t_lst **lst)
{
	t_lst	*first;
	t_philo	*philo;
	t_lst	*tmp;
	int		i;
	int		mall;

	first = NULL;
	i = 0;
	mall = 3;
	tmp = NULL;
	while (++i <= arg->phill)
	{
		if (mall_phil(&philo, first, mall))
			return (1);
		mall++;
		if (init_philo(philo, first, i, mall))
			return (1);
		mall = mall + 4;
		if (new_tmp_lst(philo, first, mall, &tmp))
			return (1);
		mall++;
		first = ft_lst_add_back(first, tmp);
	}
	*lst = first;
	return (0);
}
