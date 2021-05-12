/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:40 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/12 14:45:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_atoi_2(unsigned long long number, char **str, int sign, int *j)
{
	unsigned long long		nmb_tmp;
	int						i;

	i = *j;
	while (str[0][i] >= '0' && str[0][i] <= '9')
	{
		nmb_tmp = number;
		number = 10 * number + (str[0][i] - '0');
		if (number < nmb_tmp || number > LLONG_MAX)
		{
			if (sign == -1)
				return (-1);
			return (-2);
		}
		i++;
	}
	if ((str[0][i] < '0' || str[0][i] > 9) && str[0][i] != ' ' && str[0][i] != 0)
		return (-2);
	*j = i;
	return(number);
}

int	ft_atoi(char **str)
{
	unsigned long long		number;
	int						sign;
	int						ret;
	int						i;

	sign = 1;
	number = 0;
	i = 0;
	while ((str[0][i] >= 9 && str[0][i] <= 13) || str[0][i] == ' ')
		i++;
	if (str[0][i] < '0' || str[0][i] > '9')
		return (-1);
	number = ft_atoi_2(number, str, sign, &i);
	if (number < 0)
		return (number + 1);
	*str = &str[0][i];
	return (number * sign);
}
