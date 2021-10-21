/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:14:32 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 12:39:03 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_digit(argv[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

static void	argument_bis(t_arg *arg, char **argv, int i)
{
	arg->nb_phil = ft_atoi(argv[i++]);
	arg->tm_die = ft_atoi(argv[i++]);
	arg->tm_eat = ft_atoi(argv[i++]);
	arg->tm_sleep = ft_atoi(argv[i++]);
	arg->end_meal = 0;
	if (arg->nb_phil == -1 || arg->tm_die == -1 || \
	arg->tm_eat == -1 || arg->tm_sleep == -1)
		free_clean(NULL, NULL, 1, ER_ARG);
	if (argv[i])
	{
		arg->nb_meal = ft_atoi(argv[i]);
		if (arg->nb_meal == -1)
			free_clean(NULL, NULL, 1, ER_ARG);
	}
	else
		arg->nb_meal = -1;
}

static void	argument(t_arg *arg, char **argv)
{
	int	i;

	i = 1;
	argument_bis(arg, argv, i);
	arg->died = 0;
	arg->sec_died = malloc(sizeof(pthread_mutex_t));
	if (!arg->sec_died)
		free_clean(NULL, NULL, 1, ER_MAL);
	if (pthread_mutex_init(arg->sec_died, NULL))
		free_clean(NULL, NULL, 2, ER_MUTEX);
	arg->start = 0;
}

t_arg	*init_arg(char **argv)
{
	static t_arg	*arg;

	if (!arg)
	{
		arg = malloc(sizeof(t_arg));
		if (!arg)
			ft_error(ER_ARG);
		if (check_arg(argv))
			free_clean(NULL, NULL, 1, ER_ARG);
		argument(arg, argv);
	}
	return (arg);
}
