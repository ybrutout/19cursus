/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/29 14:08:44 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*init_arg(void)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		clean_free(NULL, 0, ER_MALLOC);
	arg->nb_philo = 0;
	arg->tm_die = 0;
	arg->tm_eat = 0;
	arg->tm_sleep = 0;
	arg->nb_eat = 0;
	return (arg);
}

int	check_arg(int argc, char **argv, t_arg *arg)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < 6)
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

