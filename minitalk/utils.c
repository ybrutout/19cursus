/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:55 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/10 12:13:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	const_value(int nb)
{
	const int	values[8] = {128, 64, 32, 16, 8, 4, 2, 1};

	return (values[nb]);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	long int	i;
	char		c;

	i = nb;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
	}
	c = (i % 10 + '0');
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}
