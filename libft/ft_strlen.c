/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:42:48 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 10:21:30 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h> 

size_t		ft_strlen(const char *s)
{
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i =0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}

int		main(void)
{
	char s[] = "\t";

	printf("F longueur ; %lu\n", ft_strlen(s));
	printf("V longueur ; %lu\n", strlen(s));
	return(0);
}