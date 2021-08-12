/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:20:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/12 16:36:18 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	init_client(char *str, int pid_server)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	send_binary(str_len, pid_server, 31);
	return (str_len);
}

void	send_binary(unsigned int nb, int pid_server, int len)
{
	int	const_bit;

	const_bit = len;
	while (const_bit > -1)
	{
		if ((nb % 2) == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		nb = nb / 2;
		usleep(90);
		const_bit--;
	}
}

int	ft_error(char *str, int argc)
{
	int	pid_server;

	pid_server = ft_atoi(str);
	if (pid_server <= 1)
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
	if (argc != 3)
		return (0);
	pid_server = ft_error(argv[1], argc);
	if (pid_server < 0)
		return (1);
	init_client(argv[2], pid_server);
	while (argv[2][i])
	{
		send_binary((unsigned int)argv[2][i], pid_server, 7);
		i++;
	}
	return (0);
}
