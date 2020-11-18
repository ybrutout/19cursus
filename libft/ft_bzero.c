/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:12:54 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/18 14:46:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(char *s, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	src = s;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}

int		main(void)
{
	char	src1[30] = "yannah loohan nahama";
	char	src2[30] = "yannah loohan nahama";
	size_t	n;

	n = 2;
	printf("avant ft : %s\n", src1);
	ft_bzero(src1, n);
	printf("après ft : %s \n", src1);
	printf("avant vrai : %s\n", src2);
	bzero(src2, n);
	printf("après vrai : %s \n", src2);
	return (0);
}