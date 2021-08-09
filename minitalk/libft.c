/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:55 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/09 15:56:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	long	num;
	int		neg;
	int		length;

	neg = 1;
	num = 0;
	length = -1;
	if (*str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && ++length > -1)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if (*str < '0' || *str > '9')
		return (-1);
	return ((int)(num * neg));
}

int		const_value(int nb)
{
	const int	values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	return (values[nb]);
}

unsigned int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int i;

	i = nb;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar(i % 10 + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	while(str[i])
		ft_putchar(str[i++]);
}
