/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:59:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/13 16:05:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_sleep(long int ms, t_lst_philo *lst)
{
	long int	start;
	t_arg		*arg;

	if (ms <= 0)
		return (0);
	arg = init_arg(0, NULL);
	start = ft_actual_time(lst->philo, lst, arg);
	while (ft_actual_time(lst->philo, lst, arg) - start < ms)
		usleep(ms / 10);
	return (start);
}

long int	ft_actual_time(t_philo *philo, t_lst_philo *lst, t_arg *arg)
{
	long int		time;
	struct timeval	g_t_o_t_d;

	time = 0;
	if (gettimeofday(&g_t_o_t_d, NULL) == -1)
		clean_free(lst, philo, arg->nb_malloc, ER_GTOD); //gestion de ca car pas propore et pas bon
	time = (g_t_o_t_d.tv_sec * 1000) + (g_t_o_t_d.tv_usec / 1000);
	return (time);
}


