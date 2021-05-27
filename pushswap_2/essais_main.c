/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:56:07 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 09:56:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int	is_in_int(int *list, int elem, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (list[i] == elem)
			return (1);
	return (0);
}

int	main(void)
{
	int			ra;
	const int	nMax = 10000;
	const int	nMin = -10000;
	const int	total = 100;
	int			*list;
	int			i;

	list = malloc(sizeof(int) * total);
	i = -1;
	srand(time(NULL));
	while (++i < total)
	{
		ra = rand() % ((nMax + 1) - nMin) + nMin;
		if (!is_in_int(list, ra, total))
			list[i] = ra;
		else
			i--;
	}
	i = -1;
	printf("make re && ./push_swap ");
	while (++i < total)
	{
		printf("%d ", list[i]);
	}
	printf(" && rm a.out\n");
	return (0);
}
