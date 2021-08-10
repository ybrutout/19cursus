/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:03:24 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/10 12:31:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	str[strlen] = '\0';
	*nb = 0;
	return (str);
}

void	stage_three(int *pid_client, int *strlen, int *stage, int i)
{
	char	*str;

	str = received_char(*strlen, i, stage);
	if (str)
	{
		ft_putstr(str);
		free(str);
		*pid_client = 0;
		*strlen = 0;
		*stage = 1;
	}
}
