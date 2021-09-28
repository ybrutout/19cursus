/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:20:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/28 15:21:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		write(1, "coucou je suis la !\n", 20);
		i++;
	}
	return (0);
}

void	*routine_b()
{
	int				i;
	pthread_mutex_t	mutex;

	i = 0;
	while (i < 100)
	{
		write(1, "hey\n", 4);
		i++;
	}
	return (0);
}

int	main(void)
{
	pthread_t	th1;
	pthread_t	th2;
	pthread_mutex_t	mtex;

	if (pthread_mutex_init(&mtex, NULL) != 0)
	{
		write(1, "Initiation muttex pas fonctioné\n", 32);
		return (5);
	}
	if (pthread_create(&th1, NULL, &routine, NULL) != 0)
	{
		write(1, "coucou\n", 7);
		return (1);
	}
	if (pthread_create(&th2, NULL, &routine_b, NULL) != 0)
	{
		write(1, "holla\n", 6);
		return (2);
	}
	if (pthread_join(th1, NULL) != 0)
	{
		write(1, "bonjour\n", 6);
		return (3);
	}
	if (pthread_join(th2, NULL) != 0)
	{
		write(1, "goedmorgen\n", 11);
		return (4);
	}
	write(1, "fin\n", 4);
	return (0);
}
