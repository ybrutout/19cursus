/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:59:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 14:42:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int i;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

t_lst	*ft_lst_add_back(t_lst *first, t_lst *new)
{
	t_lst	*tmp;

	if (!first)
		first = new;
	else
	{
		tmp = first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return (first);
}

long int	ft_atoi(char *str)
{
	int			i;
	long int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + ((long int)str[i] - '0');
		i++;
	}
	return (nb);
}
