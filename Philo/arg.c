/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/13 11:50:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg_b(char **argv, t_arg *arg, int i)
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
	return (++i);
}

static int	check_arg(int argc, char **argv, t_arg *arg)
{
	int	i;

	i = 1;
	if (argc > 4 && argc < 7)
	{
		while (i < 6 && i < argc)
		{
			if (ft_is_digit(argv[i]) == 1)
				i = check_arg_b(argv, arg, i);
			else
				break ;
		}
		if (i >= 5)
		{
			if (i == 5)
				arg->nb_eat = -1;
			return (1);
		}
	}
	clean_free(NULL, NULL, 1, ER_ARG);
	return (0);
}

t_arg	*init_arg(int argc, char **argv)
{
	static t_arg	*arg;

	if (!arg)
	{
		arg = malloc(sizeof(t_arg));
		if (!arg)
			clean_free(NULL, NULL, 0, ER_MALLOC);
		check_arg(argc, argv, arg);
		arg->nb_malloc = 1;
		arg->dead = 0;
		arg->write_mut = malloc(sizeof(pthread_mutex_t)); //gérer le nouveau malloc
		//protection de malloc
		if (pthread_mutex_init(arg->write_mut, NULL) != 0)
			clean_free(NULL, NULL, 0, ER_MALLOC);// a refaire
	}
	return (arg);
}
