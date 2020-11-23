/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:40 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/23 19:04:01 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	number;
	int	sign;
	char *new_str;

	sign = 1;
	number = 0;
	new_str = (char *)str;
	while ((*new_str >= 9 && *new_str <= 13) || *new_str == ' ')
		new_str++;
	if (*new_str == '-')
	{	
		sign *= -1;
		new_str++;
	}
	else if (*new_str == '+')
		new_str++;
	while (*new_str >= '0' && *new_str <= '9')
	{
		number = 10 * number + (*new_str - '0');
		new_str++;
	}
	return (number * sign);
}