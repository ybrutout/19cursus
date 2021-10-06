/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:20:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 15:54:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;
int				j=0;

void	*routine()
{
	int	i;

	pthread_mutex_lock(&mutex);
	i = 0;
	while (i < 10000)
	{
		write(1, "coucou je suis la !\n", 20);
		i++;
		j++;
	}
	printf("j == %d\n", j);
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(void)
{
	pthread_t		th[2];
	struct timeval	current_time;
	int				i;

	pthread_mutex_init(&mutex, NULL);
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
	i = -1;
	while (++i < 2)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
		{
			write(1, "coucou\n", 7);
			return (1);
		}
	}
	i = -1;
	while (++i < 2)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			write(1, "bonjour\n", 6);
			return (2);
		}
	}

	if (pthread_mutex_destroy(&mutex) != 0)
	{
		write(1, "Error with the destroy of mutex\n", 32);
		return (6);
	}
	write(1, "fin\n", 4);
	return (0);
}
