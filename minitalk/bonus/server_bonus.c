/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:32:59 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 10:21:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	init_client_server(int	nb, int	*stage, int len)
{
	static int	const_bit;
	static int	pid;
	static int	exposant;
	int			tmp;

	if (!const_bit)
	{
		pid = 0;
		const_bit = len;
		exposant = 0;
	}
	if (nb == 1)
		pid = pid + ft_pow(2, exposant);
	const_bit--;
	exposant++;
	if (const_bit == 2)
	{
		tmp = pid;
		pid = 0;
		const_bit = 0;
		exposant = 0;
		(*stage)++;
		return (tmp);
	}
	return (pid);
}

char	*received_char(int strlen, int i, int *stage)
{
	static char	*str;
	char		*tmp_str;
	int			tmp_char;
	int			tmp_stage;
	static int	nb;

	if (!str)
		str = init_str(strlen, &nb);
	if (nb < strlen)
	{
		tmp_stage = *stage;
		tmp_char = init_client_server(i, stage, 10);
		if (*stage > tmp_stage)
			str[nb++] = (char)tmp_char;
		if (nb == strlen)
		{
			tmp_str = str;
			write(1, "I send the message\n", 19);
			str = NULL;
			nb = 0;
			return (tmp_str);
		}
	}
	return (NULL);
}

void	received_binary(int signum)
{
	static int	pid_client;
	static int	strlen;
	static int	stage;
	int			i;

	if (!stage)
	{
		strlen = 0;
		stage = 1;
	}
	if (signum == SIGUSR1)
		i = 0;
	else
		i = 1;
	if (stage == 1)
		pid_client = init_client_server(i, &stage, 34);
	else if (stage == 2)
		strlen = init_client_server(i, &stage, 34);
	else if (stage > 2)
		i = stage_three_bonus(&strlen, &stage, i, pid_client);
	if (i == 2)
		stage = 0;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, received_binary);
	signal(SIGUSR2, received_binary);
	while (1)
		pause();
	return (0);
}
