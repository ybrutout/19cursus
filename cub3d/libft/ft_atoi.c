/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:40 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_atoi_2(unsigned long long number, char *new_str, int sign)
{
	unsigned long long		nmb_tmp;

	nmb_tmp = number;
	number = 10 * number + (*new_str - '0');
	if (number < nmb_tmp || number > LLONG_MAX)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	new_str++;
}

int	ft_atoi(const char *str)
{
	unsigned long long		number;
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
		ft_atoi_2(number, &new_str, sign);
	return (number * sign);
}
