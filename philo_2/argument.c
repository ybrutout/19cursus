/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:14:32 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 13:43:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(t_arg *arg, char **argv, int i)
{
	if (ft_is_digit(argv[i]) == 0)
	{
		free_clean(arg, NULL, 1, BAD_ARG);
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
		free_clean(arg, NULL, 1, ER_MAL);
	*(arg->wait) = 0;
	arg->extra = malloc(sizeof(pthread_mutex_t));
	if (!(arg->extra))
		free_clean(arg, NULL, 2, ER_MAL);
	if (pthread_mutex_init(arg->extra, NULL))
		free_clean(arg, NULL, 3, ER_MUTEX);
	return (arg);
}
