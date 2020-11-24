/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:40 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 13:02:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long int	number;
	int						sign;
	char					*new_str;

	sign = 1;
	number = 0;
	new_str = (char *)str;
	while ((*new_str >= 9 && *new_str <= 13) || *new_str == ' ')
		new_str++;
	if (*new_str == '-' && new_str++)
		sign *= -1;
	else if (*new_str == '+')
		new_str++;
	while (*new_str >= '0' && *new_str <= '9')
	{
		number = 10 * number + (*new_str - '0');
		if (number >= LLONG_MAX && sign == -1)
			return (0);
		else if (number >= LLONG_MAX && sign == 1)
			return (-1);
		new_str++;
	}
	return (number * sign);
}
