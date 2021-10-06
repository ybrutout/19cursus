/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 15:16:36 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg		*arg;
	t_lst_philo	*lst_phil;
	long int	now;

	arg = init_arg(argc, argv);
	printf("nb_philo == %d\ntm_die == %ld\n", arg->nb_philo, arg->tm_die);
	printf("tm_eat == %ld\n", arg->tm_eat);
	printf("tm_sleep == %ld\n nb_eat == %d\n", arg->tm_sleep, arg->nb_eat);
	lst_phil = init_lst_philo(arg);
	now = actual_time(lst_phil->philo, lst_phil, arg);
	printf("time == %ld\n", now);
	return (0);
}
