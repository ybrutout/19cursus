/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:23:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/09 15:27:03 by ybrutout         ###   ########.fr       */
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

int		init_client(int	nb, int	*stage, int len)
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

char	*received_char(int pid_client, int strlen, int i, int stage)
{
	static char *str;
	char		*tmp_str;
	int			tmp_char;
	int			tmp_stage;
	int			nb;

	if (!str)
	{
		str = malloc(sizeof(char) * (strlen + 1));
		str[strlen] = '\0';
		nb = 0;
	}
	if (nb < (strlen))
	{
		tmp_stage = stage;
		tmp_char = init_client(i, &stage, 10);
		if (stage > tmp_stage)
		{
			str[nb] = (char)tmp_char;
			nb++;
		}
		if (nb == strlen)
		{
			tmp_str = str;
			str = NULL;
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
	static char	*str;

	if (!strlen && !stage)
	{
		strlen = 0;
		stage = 1;
	}
	if (signum == SIGUSR1)
		i = 0;
	else
		i = 1;
	if (stage == 1)
		pid_client = init_client(i, &stage, 34);
	else if (stage == 2)
		strlen = init_client(i, &stage, 34);
	else if (stage > 2)
	{
		str = received_char(pid_client, strlen, i, stage);
		if (str)
		{
			printf("%s\n", str);
			free(str);
			str = NULL;
			pid_client = 0;
			strlen = 0;
			stage = 1;
		}
	}
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
