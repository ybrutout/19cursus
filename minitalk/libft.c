/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:55 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/05 16:01:58 by ybrutout         ###   ########.fr       */
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

char	*itoa_base_remix(int nb, int size)//pas sure d'en avoir encore besoin
{
	char	*c;

	c = malloc(sizeof(char) * size);
	if (!c)
		return (NULL);
	c[--size] = '\0';
	while (nb)
	{
		c[--size] = nb % 2 + 48;
		nb /= 2;
	}
	while (size > -1)
	{
		c[--size] = '0';
	}
	return (c);
}
