/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:20:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/05 15:26:55 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	char_in_binary(int c, int pid)
{
	char	*binary;

	binary = itoa_base_remix(c, 8);
	if (!binary)
		return(0);//changer malloc
	//send_binary(&binary, pid);
	return (1);
}

int	str_in_binary(char *str, int pid)
{
	char	c;

	while (*str)
	{
		c = *str;
		char_in_binary((int)c, pid);
		str++;
	}
	return (1);
}

void	send_binary_pid(int nb, int pid_server)
{
	int i;
	int	const_bit;

	i = 7;
	const_bit = 32;
	while (const_bit > -1)
	{
		if ((nb % 2) == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		nb = nb / 2;
		usleep(8);
		const_bit--;
	}
}

int	init_client(char *str, int pid_server)
{
	int 			pid_client;
	unsigned int	str_len;

	pid_client = getpid();
	send_binary_pid(pid_client, pid_server);
	exit(EXIT_SUCCESS);
	str_len = ft_strlen(str);
	return(pid_client);
}

int	main(int argc, char **argv)
{
	int pid_server;
	int	pid_client;

	if (argc != 3) //rajouter si pid == -1
	{
		write(1, "Error\nWrong argument\n", 21);
		exit(EXIT_FAILURE);
	}
	pid_server = ft_atoi(argv[1]);
	pid_client = init_client(argv[2], pid_server);
	str_in_binary(argv[2], pid_server);
	return (0);
}
