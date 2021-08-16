/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:21:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 10:24:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(char *str)
{
	long	num;
	int		neg;
	int		length;
	int		i;

	neg = 1;
	num = 0;
	length = -1;
	i = 0;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && ++length > -1)
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	if ((num * neg) > INT_MAX)
		return (-1);
	return ((int)(num * neg));
}

int	ft_error_message(int message)
{
	if (message == MALLOC_ERROR)
	{
		write(1, "Error\nMalloc error\n", 19);
		exit(EXIT_FAILURE);
	}
	if (message == PID_ERROR)
	{
		write(1, "Error\nWrong PID\n", 16);
		return (-1);
	}
	if (message == ARG_ERROR)
	{
		write(1, "Error\nNot the right number of argument\n", 39);
		exit(-1);
	}
	if (message == END)
		exit(EXIT_SUCCESS);
	return (0);
}
