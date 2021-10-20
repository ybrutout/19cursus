/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 16:22:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*thread_time(t_philo *philo, t_lst *lst)
{
	pthread_mutex_t	*time;

	time = malloc(sizeof(pthread_mutex_t));
	if (!time)
		free_clean(philo, lst, ((philo->arg->nb_phil * 4) + 3), ER_MAL);
	if (pthread_mutex_init(time, NULL) != 0)
	{
		free(time);
		free_clean(philo, lst, ((philo->arg->nb_phil * 4) + 3), ER_MUTEX);
	}
	return (time);
}

void	send_the_thread(t_lst *lst, t_arg *arg)
{
	t_lst			*tmp;
	pthread_mutex_t	*time;

	tmp = lst;
	time 
	while (tmp)
	{
		tmp->philo->last_eat = arg->start;
		if (pthread_create(&tmp->philo->philo_add, NULL, routine, (void *)tmp))
			free_clean(tmp->philo, lst, ((arg->nb_phil * 4) + 3), ER_THR);
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (pthread_join(tmp->philo->philo_add, NULL) != 0)
			free_clean(lst->philo, lst, ((arg->nb_phil * 4) + 3), ER_THR);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_lst	*lst;

	if (argc < 5 || argc > 6)
		ft_error(ER_ARG);
	arg = init_arg(argv);
	printf("nb_phil == %d\ntm_die == %ld\ntm_eat == %ld\n", arg->nb_phil, arg->tm_die, arg->tm_eat);//test
	printf("tm_sleep == %ld\nnb_meal == %d\n", arg->tm_sleep, arg->nb_meal);//test
	printf("died == %d\nsec_died == %p\n\n", arg->died, arg->sec_died);//test
	lst = init_lst(arg);
	arg->start = get_current();
	send_the_thread(lst, arg);
	free_clean(lst->philo, lst, ((arg->nb_phil * 4) + 3), END);
	return (0);
}
