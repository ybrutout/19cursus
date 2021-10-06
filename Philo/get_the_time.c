/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:59:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 15:32:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	actual_time(t_philo *philo, t_lst_philo *lst, t_arg *arg)
{
	long int		time;
	struct timeval	g_t_o_t_d;

	time = 0;
	if (gettimeofday(&g_t_o_t_d, NULL) == -1)
		clean_free(lst, philo, arg->nb_malloc, ER_GTOD);
	time = (g_t_o_t_d.tv_sec * 1000) + (g_t_o_t_d.tv_usec / 1000);
	return (time);
}


