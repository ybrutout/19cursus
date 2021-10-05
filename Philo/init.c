/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/05 16:41:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*init_arg(void)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		clean_free(NULL, NULL, 0, ER_MALLOC);
	arg->nb_philo = 0;
	arg->tm_die = 0;
	arg->tm_eat = 0;
	arg->tm_sleep = 0;
	arg->nb_eat = 0;
	return (arg);
}

t_philo		*init_philo(int i, t_arg *arg)// pas sure que j'en ai besoin
{
	t_philo 				*philo;
	pthread_t				*philo_id;
	static pthread_mutex_t	*l_f;

	if (!l_f)
		l_f = NULL;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i + 1;
	pthread_mutex_init(philo->fork_right, NULL);
	philo->fork_left = l_f;
	if (i > 0)
		l_f = philo->fork_right;


}

int			init_fork(t_philo *philo, t_lst_philo *first, t_arg	*arg, int i)
{
	static pthread_mutex_t	*last;

	philo->fork_right = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork_right)
		return (0);
	if (pthread_mutex_init(philo->fork_right, NULL) != 0)
		return (0);
	if (i == 0)
		philo->fork_left = philo->fork_right;
	else if (i == arg->nb_philo - 1)
	{
		philo->fork_left = last;
		first->philo->fork_left = philo->fork_right;
	}
	else
		philo->fork_left = last;
	last = philo->fork_right;
	return (1);
}

t_lst_philo	*new_lst_philo(t_philo *philo)
{
	t_lst_philo	*new;

	new = malloc(sizeof(t_lst_philo));
	if (!new)
		return (NULL);
	new->philo = philo;
	new->next = NULL;
	return (new);
}

t_lst_philo	*init_lst_philo(t_arg *arg)
{
	t_lst_philo	*first;
	t_lst_philo	*last;
	t_philo		*philo;
	int			i;

	first = NULL;
	i = 0;
	while (i < arg->nb_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			clean_free(arg, first, (i * 2) + 1, ER_MALLOC);
		philo->id = i + 1;
		philo->tm_die = arg->tm_die;
		philo->lst_eat = 0;
		if (init_fork(philo, first, arg, i) == 0)
			clean_free(arg, first, (i * 2)+ 2, ER_MALLOC);
		last = new_lst_philo(philo);
		if (!last)
			clean_free(arg, first, 8, ER_MALLOC);// a revoir
		ft_lst_add_back(first, last);
	}
	return (first);
}

int	check_arg(int argc, char **argv, t_arg *arg)
{
	int	i;

	i = 1;
	if (argc > 1 && argc < 7)
	{
		while (i < 6 && i < argc)
		{
			if (ft_is_digit(argv[i]) == 1)
			{
				if (i == 1)
					arg->nb_philo = ft_atoi(argv[i]);
				if (i == 2)
					arg->tm_die = ft_atoi(argv[i]);
				if (i == 3)
					arg->tm_eat = ft_atoi(argv[i]);
				if (i == 4)
					arg->tm_sleep = ft_atoi(argv[i]);
				if (i == 5)
					arg->nb_eat = ft_atoi(argv[i]);
				i++;
			}
			else
				break;
		}
		if ( i >= 5)
			return (1);
	}
	return (0);
}

