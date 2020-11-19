/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:43:09 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 10:07:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s11;
	char	*s22;
	size_t	i;

	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (!(s11[i] == s22[i]))
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

int		main(void)
{
	char	*s1 = "yannahloohannahama";
	char	*s2 = "yannahloohanNahama";
	size_t	n;

	n = 50;
	printf("F compare : %d\n", ft_memcmp(s1, s2, n));
	printf("V compare : %d\n", memcmp(s1, s2, n));
	return (0);
}