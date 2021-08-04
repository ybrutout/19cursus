/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:23:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/04 17:07:05 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	user_one(int signum)
{
	if (signum == 30)
		printf("1");
}

void	user_two(int signum)
{
	if (signum == 31)
		printf("0");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID == %d\n", pid);
	signal(SIGUSR1, user_one);
	signal(SIGUSR2, user_two);
	while (1)
		pause();
	return (1);
}
