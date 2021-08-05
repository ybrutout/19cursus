/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:23:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/05 16:20:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_pow(int nb, int exposant)
{
	int i;
	int	value;

	i = 0;
	value = 1;
	while(i < exposant)
	{
		value = value * nb;
		i++;
	}
	return (value);
}

int		init_pid_client(int	nb)
{
	static int	const_bit;
	static int	pid;
	static int	exposant;

	if (!const_bit)
	{
		pid = 1;
		const_bit = 31;
		exposant = 0;
	}
	if (const_bit == -1)
		return (0);
	else
	{
		if (nb == 1)
			pid = pid + ft_pow(2, exposant);
		const_bit--;
	}
	return (pid);
}

void	received_binary(int signum)
{
	static int	pid_client;
	static int	strlen;
	static char	*str;
	int			i;

	if (signum == SIGUSR1)
		i = 0;
	else
		i = 1;
	if (init_pid_client(i) != -1)
		pid_client = init_pid_client(i);
	printf("pid == %d\n", pid_client);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID == %d\n", pid);//creer putnbr
	signal(SIGUSR1, received_binary);
	signal(SIGUSR2, received_binary);
	while (1)
		pause();
	return (0);
}
