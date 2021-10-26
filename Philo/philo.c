/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 15:58:15 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	send_the_thread(t_lst *lst, t_arg *arg)
{
	t_lst		*tmp;
	pthread_t	time;

	tmp = lst;
	while (tmp)
	{
		tmp->philo->last_eat = arg->start;
		if (pthread_create(&tmp->philo->philo_add, NULL, routine, (void *)tmp))
			return (free_clean(tmp->philo, lst, ((arg->phill * 4) + 3), THR));
		tmp = tmp->next;
	}
	if (pthread_create(&time, NULL, routine_time, (void *)lst))
		return (free_clean(tmp->philo, lst, ((arg->phill * 4) + 3), THR));
	tmp = lst;
	while (tmp)
	{
		if (pthread_detach(tmp->philo->philo_add))
			return (free_clean(lst->philo, lst, ((arg->phill * 4) + 3), THR));
		tmp = tmp->next;
	}
	if (pthread_join(time, NULL))
		return (free_clean(lst->philo, lst, ((arg->phill * 4) + 3), THR));
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_lst	*lst;

	if (argc < 5 || argc > 6)
		return (ft_error(ER_ARG));
	if (init_arg(argv, &arg))
		return (1);
	if (init_lst(arg, &lst))
		return (1);
	arg->start = get_current();
	if (send_the_thread(lst, arg))
		return (1);
	free_clean(lst->philo, lst, ((arg->phill * 4) + 3), END);
	return (0);
}
