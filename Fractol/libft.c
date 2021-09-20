/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:14:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/20 15:52:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int		ft_strlen(const char *s)
{
	char	*s1;
	int	i;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (1)
	{
		if ((!*s1 && !*s2) || !n)
			return (0);
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (-1);
	}
}

int	is_digit_or_comma(char *str)
{
	int	i;
	int comma;

	i = 0;
	comma = 1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-')
		{
			if (str[i] == '.' && comma == 1)
				comma = -1;
			else if (str[i] == '.' && comma == -1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (i * comma);
}

long double	ft_atoi(char *str)
{
	long double	unit;
	long double dec;
	int			neg;
	int			comma;
	int			i;

	neg = 1;
	unit = 0;
	dec = 0;
	comma = 0;
	i = is_digit_or_comma(str);
	if (i == 0)
		return (0);
	else if (i < 0)
	{
		i = (i * -1) - 1;
		comma = 1;
	}
	while ((str[i] >= '0' && str[i] <= '9' && i >= 0) || str[i] == '.')
	{

		if (str[i] == '.')
			comma = 0;
		else if (comma == 1)
			dec = (dec + (str[i] - '0')) / 10;
		else
			unit = 10 * unit + (str[i] - '0');
		i--;
	}
	if (str[i] == '-')
		neg *= -1;
	return ((long double) ((unit + dec) * neg));
}
