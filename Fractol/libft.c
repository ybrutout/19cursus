/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:14:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/24 13:40:48 by ybrutout         ###   ########.fr       */
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
