/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/20 16:58:49 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	send_the_thread(t_lst *lst, t_arg *arg)
{
	t_lst		*tmp;
	pthread_t	time;

	tmp = lst;
	if (pthread_create(&time, NULL, routine_time, (void *)lst))
		free_clean(tmp->philo, lst, ((arg->nb_phil * 4) + 3), ER_THR);
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
	lst = init_lst(arg);
	arg->start = get_current();
	send_the_thread(lst, arg);
	free_clean(lst->philo, lst, ((arg->nb_phil * 4) + 3), END);
	return (0);
}
