/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:14:32 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 16:09:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(t_arg *arg, char **argv, int i)
{
	if (ft_is_digit(argv[i]) == 0)
	{
		free_clean(arg, NULL, NULL, 1, BAD_ARG);
		return (0);
	}
	if (i == 1)
		arg->nb_phil = ft_atoi(argv[i]);
	if (i == 2)
		arg->tm_die = ft_atoi(argv[i]);
	if (i == 3)
		arg->tm_eat = ft_atoi(argv[i]);
	if (i == 4)
		arg->tm_sleep = ft_atoi(argv[i]);
	if (i == 5)
		arg->nb_meal = ft_atoi(argv[i]);
	return (1);
}

t_arg	*init_arg(t_arg *arg, char **argv)
{
	int	i;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		ft_error(ER_MAL);
	i = 0;
	arg->nb_meal = -1;
	while (argv[++i])
		if (check_arg(arg, argv, i) == 0)
			return (NULL);
	arg->died = 0;
	arg->wait = malloc(sizeof(int));
	if (!(arg->wait))
		free_clean(arg, NULL, NULL, 1, ER_MAL);
	*(arg->wait) = 0;
	arg->extra = malloc(sizeof(pthread_mutex_t));
	if (!(arg->extra))
		free_clean(arg, NULL, NULL, 2, ER_MAL);
	if (pthread_mutex_init(arg->extra, NULL))
		free_clean(arg, NULL, NULL, 3, ER_MUTEX);
	return (arg);
}

static int	init_fork(t_philo *philo, t_lst **first, t_arg	*arg, int i, int *mall)
{
	static pthread_mutex_t	*last;

	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		return (1);
	*mall = *mall + 1;
	if (pthread_mutex_init(philo->fork_right, NULL) != 0)
		return (1);
	*mall = *mall + 1;
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
	return (0);
}

t_philo	*init_philo(t_arg *arg, t_lst **first, int *mall, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		free_clean(arg, (*first)->philo, *first, *mall, ER_MAL);
	*mall = *mall + 1;
	philo->id = i;
	philo->last_eat = 0;
	philo->start = 0;
	if (init_fork(philo, first, arg, i, mall))
		free_clean(arg, philo, *first, *mall, ER_MAL);
	return (philo);
}

t_lst	*init_lst(t_arg *arg)
{
	t_lst	*first;
	t_lst	*new;
	t_philo	*philo;
	int		i;
	int		mall;

	first = NULL;
	i = 1;
	mall = 4;
	while(i <= arg->nb_phil)
	{
		philo = init_philo(arg, &first, &mall, i);
		new = malloc(sizeof(t_lst));
		if (!new)
			free_clean(arg, philo, first, mall, ER_MAL);
		mall++;
		new->philo = philo;
		new->next = NULL;
		first = ft_lst_add_back(first, new);
		i++;
	}
	return (first);
}
