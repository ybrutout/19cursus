/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:33:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 11:10:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_pow(int nb, int exposant)
{
	int	i;
	int	value;

	i = 0;
	value = 1;
	while (i < exposant)
	{
		value = value * nb;
		i++;
	}
	return (value);
}

char	*init_str(int strlen, int *nb)
{
	char	*str;

	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		ft_error_message(MALLOC_ERROR);
	str[strlen] = '\0';
	nb = 0;
	return (str);
}

int	stage_bonus(int *strlen, int *stage, int i, int pid_client)
{
	char	*str;

	str = received_char(*strlen, i, stage);
	if (str)
	{
		ft_putstr(str);
		free(str);
		write(1, "Confirmation of reception sent to client\n", 41);
		kill(pid_client, SIGUSR2);
		return (2);
	}
	else
	{
		kill(pid_client, SIGUSR1);
	}
	return (0);
}
