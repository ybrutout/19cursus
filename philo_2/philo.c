/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 13:39:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;

	if (argc < 5 || argc > 6)
		ft_error(BAD_ARG);
	arg = init_arg(arg, argv);
	printf("nb_phil == %d\ntm_die == %ld\ntm_eat == %ld\n", arg->nb_phil, arg->tm_die, arg->tm_eat);
	printf("tm_sleep == %ld\nnb_meal == %d\nwait == %d\n", arg->tm_sleep, arg->nb_meal, *(arg->wait));
	printf("wait add == %p\ndied == %d\nextra == %p\n", arg->wait, arg->died, arg->extra);
	return (0);
}
