/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:43:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/24 10:53:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_position(t_num *col, int *lst_sort, int half, int len)
{
	int max;
	int min;
	int sc_max;
	int sign = 0;

	if ((max = position_for(col, lst_sort[len - 1])) > (len / 2))
	{
		sign = 1;
		max = len - max;
	}
	printf("max 1 == %d\n", max); // tests
	if ((min = position_for(col, lst_sort[len - half])) > (len / 2))
	{
		if (max > ((len - min) + 3))
		{
			sign = 1;
			max = len - min;
		}
	}
	else if (max > (min + 3))
	{
		sign = 0;
		max = min;
	}
	if ((sc_max= position_for(col, lst_sort[len - 2])) > (len / 2))
	{
		if (max > ((len -sc_max) + 2))
		{
			sign = 1;
			max = len - sc_max;
		}
	}
	else if (max > (sc_max + 2))
	{
		sign = 0;
		max = sc_max;
	}
	if (sign == 1)
		max *= -1;
	printf("max 2 == %d\n", max); //tests
	return(max);
}

int	sorted_five_hundred(t_col **index, int **lst_sort)
{
	int	half;
	int	i = 0;
	int	tmp=0;

	if (middlepoint_first(index, lst_sort) == 0)
		return (0);
	while ((ascending((*index)->col_a, (*index)->len_a) == 0) && (*index)->len_a > 2)
	{
		half = ((*index)->len_a)/2;
		if (middlepoint(index, lst_sort) == 0)
			return(0);
		i++;
		if (i == 4)
			exit(EXIT_SUCCESS);
	}
	if (ascending((*index)->col_a, (*index)->len_a) != 1)
		rotate(index, 1);
	if (half != (*index)->len_a)
		half = (half * 2) - ((*index)->len_a);
	while ((*index)->len_b > 0)
	{
		while (half != 0)
		{
			tmp = (*index)->len_b;
			printf("half == %d\n", half);
			*lst_sort = nw_lst_order(&(*index)->col_b, *lst_sort, tmp, 1);
			if ((*index)->col_b->nb == (*index)->max_b)
			{
				push(index, 2);
				if ((*index)->col_a->nb > (*index)->col_a->next->nb)
					swap_button(index, 1);
			}
			else if ((*index)->col_b->nb == lst_sort[0][tmp - 2] && (*index)->min_a > (*index)->max_b)
				push(index, 2);
			else if ((*index)->col_b->nb == lst_sort[0][tmp - half] && tmp > 2)
			{
				push(index, 2);
				rotate(index, 1);
			}
			else if (big_position((*index)->col_b, *lst_sort, half, (*index)->len_b) >= 0)
				rotate(index, 2);
			else if (big_position((*index)->col_b, *lst_sort, half, (*index)->len_b) < 0)
				reverse_rot(index, 2);
			half--;
			//	exit(EXIT_SUCCESS);
		}
		while ((*index)->last_a < (*index)->col_a->nb)
			reverse_rot(index, 1);
		i++;
		printf("je suis la regarde moi j'ai besoin que tu me vois !!!! \n");
		if (i == 2)
			exit(EXIT_SUCCESS);
		half = (*index)->len_a;
	}
	exit(EXIT_SUCCESS);
	//mettre condition si il est desordre croissqnt
	return (1);
}
