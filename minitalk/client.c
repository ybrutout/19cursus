/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:20:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/10 11:15:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	init_client(char *str, int pid_server)
{
	int				pid_client;
	unsigned int	str_len;

	pid_client = getpid();
	send_binary(pid_client, pid_server, 31);
	str_len = ft_strlen(str);
	send_binary(str_len, pid_server, 31);
	return (pid_client);
}

void	send_binary(int nb, int pid_server, int len)
{
	int	i;
	int	const_bit;

	i = 7;
	const_bit = len;
	while (const_bit > -1)
	{
		if ((nb % 2) == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		nb = nb / 2;
		usleep(100);
		const_bit--;
	}
}

int	ft_error(char *str, int argc)
{
	int	pid_server;

	pid_server = ft_atoi(str);
	if (pid_server < 0)
		return (ft_error_message(PID_ERROR));
	if (argc != 3)
		return (ft_error_message(ARG_ERROR));
	return (pid_server);
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	i = 0;
	pid_server = ft_error(argv[1], argc);
	if (pid_server < 0)
		return (1);
	init_client(argv[2], pid_server);
	while (argv[2][i])
	{
		send_binary((int)argv[2][i], pid_server, 7);
		i++;
	}
	return (0);
}
