/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/19 15:43:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_lst	*lst;
	t_lst	*tmp;

	if (argc < 5 || argc > 6)
		ft_error(ER_ARG);
	arg = init_arg(argv);
	printf("nb_phil == %d\ntm_die == %ld\ntm_eat == %ld\n", arg->nb_phil, arg->tm_die, arg->tm_eat);//test
	printf("tm_sleep == %ld\nnb_meal == %d\n", arg->tm_sleep, arg->nb_meal);//test
	printf("died == %d\nsec_died == %p\n\n", arg->died, arg->sec_died);//test
	lst = init_lst(arg);
	arg->start = get_current();
	tmp = lst;
	while (tmp)
	{
		tmp->philo->last_eat = arg->start;
		if (pthread_create(&tmp->philo->philo_add, NULL, routine, (void *)tmp))
			free_clean(tmp->philo, lst, ((arg->nb_phil * 6) + 3), ER_THR);
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (pthread_join(tmp->philo->philo_add, NULL) != 0)
			free_clean(lst->philo, lst, ((arg->nb_phil * 6) + 3), ER_THR);
		tmp = tmp->next;
	}
	return (0);
}
