/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:08:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/24 16:14:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *find_the_pivot(int **lst_sort, int len)
{
	int	*tmp;
	int pivot;

	tmp = malloc(sizeof(int) * 5);
	if (!tmp)
		return(0);
	pivot = len / 5;
	tmp[0] = lst_sort[0][pivot];
	tmp[1] = lst_sort[0][pivot * 2];
	tmp[2] = lst_sort[0][pivot * 3];
	tmp[3] = lst_sort[0][pivot * 4];
	tmp[4] = lst_sort[0][len - 1];
	return (tmp);
}

void	stacka_sort(t_col **index, int **lst_sort, int *pivot, int len_pivot)
{
	int	down;
	int	i;

	(*index)->stack += 2;
	len_pivot /= 2;
	while ((*index)->len_a != (*index)->stack)
	{
		i = 0;
		*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 1);
		down = lst_sort[0][((*index)->len_a - 1) - len_pivot];
		while (i < (len_pivot))
		{
			if ((*index)->col_a->nb <= down)
			{
				i++;
				push(index, 1);
			}
			else
				rotate(index, 1);
			printf("len_pivot == %d\n", len_pivot);
			printf("i == %d\n", i);
			printf("down == %d\n", down);
		}
		printf("je suis bloque la \n");
		len_pivot /= 2;
		printf("len_pivot == %d\n", len_pivot);
		printf("i == %d\n", i);
	}
	exit(EXIT_SUCCESS);
}

void	stackb_sort(t_col **index, int **lst_sort, int *pivot, int len_pivot)
{
	int	i;
	int down;

	len_pivot = len_pivot / 2;
	*lst_sort = nw_lst_order(&(*index)->col_b, *lst_sort, (*index)->len_b, 1);
	down = lst_sort[0][((*index)->len_b - 1) - len_pivot];
	i = 0;
	while (i < len_pivot)
	{
		if ((*index)->col_b->nb > down)
		{
			i++;
			push(index, 2);
		}
		else
			rotate(index, 2);
	}
	while ((*index)->last_b > lst_sort[0][((*index)->len_b - 1) - (len_pivot * 2)])
		reverse_rot(index, 2);
	stacka_sort(index, lst_sort, pivot, len_pivot);
	exit(EXIT_SUCCESS);
}

int big_sorted(t_col **index, int **lst_sort)
{
	int i = 0; //test
	int *pivot;
	int	j;
	int	len_pivot;

	while ((*index)->len_a != 0)
	{
		*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->argc, 1);
		if (!*lst_sort)
			return(0);
		while (i < (*index)->argc)//test
			printf("lst == %d\n", lst_sort[0][i++]); //test
		pivot = find_the_pivot(lst_sort, (*index)->len_a);
		if (!pivot)
			return(0);
		i = 0; //test
		while (i < 5)//test
			printf("pivot == %d\n", pivot[i++]);//test
		j = 0;
		len_pivot = ((*index)->len_a) / 5 ;
		while (j < 5)
		{
			i = 0;
			while ( len_pivot > i)
			{
				if ((*index)->col_a->nb <= pivot[j])
				{
					push(index, 1);
					i++;
				}
				else
						rotate(index, 1);
			}
			j++;
		}
	}
	stackb_sort(index, lst_sort, pivot, len_pivot);
	exit(EXIT_SUCCESS);
	free(pivot);
	return (1);
}
