/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:32:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/12 16:35:46 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	init_client(char *str, int pid_server)
{
	unsigned int	str_len;
	int				pid_client;

	pid_client = getpid();
	send_binary(pid_client, pid_server, 31);
	str_len = ft_strlen(str);
	send_binary(str_len, pid_server, 31);
	if (!the_struct(pid_server, str_len, str, INIT))
		return (-1);
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
		usleep(1000);
		const_bit--;
	}
}

void	send_str(int signum)
{
	t_gen	*general;

	general = the_struct(0, 0, NULL, RECEVE);
	if (signum == SIGUSR1)
	{
		if (!general)
			ft_error_message(END);
		if ((general->nb % 2) == 1)
		{
			kill(general->pid_server, SIGUSR2);
			general = the_struct(1, 0, NULL, CHANGE);
		}
		else if ((general->nb % 2) == 0)
		{
			kill(general->pid_server, SIGUSR1);
			general = the_struct(0, 0, NULL, CHANGE);
		}
	}
	else
	{
		free(general);
		write(1, "Error signal\n", 13);
		exit(EXIT_FAILURE);
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

	if (argc != 3)
		return (0);
	pid_server = ft_error(argv[1], argc);
	if (pid_server < 0)
		return (1);
	if (init_client(argv[2], pid_server) < 0)
		return (1);
	send_str(SIGUSR1);
	signal(SIGUSR1, send_str);
	signal(SIGUSR2, send_str);
	while (1)
		pause();
	return (0);
}
