/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:42:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 10:07:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_philo *philo, t_lst_philo **first, t_arg	*arg, int i)
{
	static pthread_mutex_t	*last;

	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		return (0);
	if (pthread_mutex_init(philo->fork_right, NULL) != 0)
		return (0);
	if (i == 0)
		philo->fork_left = philo->fork_right;
	else if (i == arg->nb_philo)
	{
		philo->fork_left = last;
		(*first)->philo->fork_left = philo->fork_right;
	}
	else
		philo->fork_left = last;
	last = philo->fork_right;
	return (1);
}

static t_lst_philo	*new_lst_philo(t_philo *philo)
{
	t_lst_philo	*new;

	new = malloc(sizeof(t_lst_philo));
	if (!new)
		return (NULL);
	new->philo = philo;
	new->next = NULL;
	return (new);
}

static t_philo	*init_b(t_lst_philo *first, int mal, int i, int *beguin)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		clean_free(first, NULL, mal, ER_MALLOC);
	mal++;
	philo->lst_eat = 0;
	philo->id = i;
	philo->extra = beguin;
	return (philo);
}

t_lst_philo	*init_lst_philo(t_arg *arg, int *beguin)
{
	t_lst_philo	*first;
	t_lst_philo	*last;
	t_philo		*philo;
	int			i;
	int			mal;

	first = NULL;
	i = 1;
	mal = 1;
	while (i <= arg->nb_philo)
	{
		philo = init_b(first, mal, i, beguin);
		if (init_fork(philo, &first, arg, i) == 0)
			clean_free(first, philo, mal, ER_MALLOC);//gestion des erreurs à changé
		mal++;
		last = new_lst_philo(philo);
		if (!last)
			clean_free(first, philo, mal, ER_MALLOC);//gestion des erreurs à changé
		mal++;
		if (i == arg->nb_philo)
			last->next = first;
		first = ft_lst_add_back(first, last);
		i++;
	}
	arg->nb_malloc = mal;
	return (first);
}
