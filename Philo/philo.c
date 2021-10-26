/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:15:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/26 11:14:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	send_the_thread(t_lst *lst, t_arg *arg)
{
	t_lst		*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->philo->last_eat = arg->start;
		if (pthread_create(&tmp->philo->philo_add, NULL, routine, (void *)tmp))
			return (free_clean(tmp->philo, lst, ((arg->phill * 4) + 3), THR));
		tmp = tmp->next;
	}
	while (1)
	{
		tmp = lst;
		while (tmp)
		{
			if (((get_current() - lst->philo->last_eat) / 1000) \
			>= tmp->philo->arg->tm_die)
			{
				arg->died = 1;
				ft_write(DEAD, tmp->philo);
				break ;
			}
			else if (arg->nb_meal != -1 && arg->end_meal == arg->phill)
			{
				arg->died = 1;
				break;
			}
			else
				tmp = tmp->next;
		}
		if (arg->died == 1 || arg->end_meal == arg->phill)
			break ;
	}
	tmp = lst;
	while (tmp)
	{
		if (pthread_join(tmp->philo->philo_add, NULL))
			return (free_clean(lst->philo, lst, ((arg->phill * 4) + 3), THR));
		tmp = tmp->next;
	}
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
