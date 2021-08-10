/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:32:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/10 17:22:15 by ybrutout         ###   ########.fr       */
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
	the_struct(pid_server, str);
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
		usleep(100);
		const_bit--;
	}
}

t_gen	*the_struct(int pid_server, char *arg)
{
	static t_gen	*general;

	if (!general)
	{
		general = malloc(sizeof(t_gen) * 1);
		if (!general)
			return (NULL);
		general->const_bit = 7;
		general->nb = 0;
		general->pid_server = pid_server;
		general->str = arg;
		return (general);
	}
}

void	send_str(int signum)
{
	t_gen *general;

	general = the_struct(0, NULL);
	if (signum == SIGUSR1)
	{
		if (general->const_bit > -1)
		{
			if ((general->nb % 2) == 1)
				kill(general->pid_server, SIGUSR2);
			else
				kill(general->pid_server, SIGUSR1);
		}
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
		send_str((unsigned int)argv[2][i], pid_server, 7);
		i++;
	}
	return (0);
}
