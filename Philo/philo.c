/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/29 14:03:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;

	arg = init_arg();
	if (check_arg(argc, argv, arg) != 1)
		clean_free(arg, 1, ER_ARG);
	printf("nb_philo == %d\ntm_die == %ld\ntm_eat == %ld\ntm_sleep == %ld\nnb_eat == %d\n", arg->nb_philo, arg->tm_die, arg->tm_eat, arg->tm_sleep, arg->nb_eat);
	return (0);
}
