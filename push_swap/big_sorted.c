/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:43:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/23 16:25:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_position(t_num *col, int *lst_sort, int half, int len)
{
	int max;
	int min;
	int sc_max;
	int sign = 0;

	if ((max = position_for(col, lst_sort[half])) > (len / 2))
	{
		sign = 1;
		max = len - max;
	}
	if ((min = position_for(col, lst_sort[0])) > (len / 2))
	{
		if (max > (len - min))
		{
			sign = 1;
			max = len - min;
		}
	}
	else if (max > min)
	{
		sign = 0;
		max = min;
	}
	if ((sc_max= position_for(col, lst_sort[half - 1])) > (len / 2))
	{
		if (max > (len -sc_max))
		{
			sign = 1;
			max = len - sc_max;
		}
	}
	else if (max > sc_max)
	{
		sign = 0;
		max = sc_max;
	}
	if (sign == 1)
		max *= -1;
	return(max);
}

int	sorted_five_hundred(t_col **index, int **lst_sort)
{
	int	half;
	int	i = 0;

	if (middlepoint_first(index, lst_sort) == 0)
		return (0);
	while ((ascending((*index)->col_a, (*index)->len_a) == 0) && (*index)->len_a > 2)
	{
		half = ((*index)->len_a)/2;
		if (middlepoint(index, lst_sort) == 0)
			return(0);
	}
	if (ascending((*index)->col_a, (*index)->len_a) != 1)
		rotate(index, 1);
	if (half != (*index)->len_a)
		half = (half * 2) - ((*index)->len_a);
	while ((*index)->len_b > 0)
	{
		while (half != 0)
		{
			*lst_sort = nw_lst_order(&(*index)->col_b, *lst_sort, (half - 1), 1);
			if ((*index)->col_b->nb == (*index)->max_b)
			{
				push(index, 2);
				if ((*index)->col_a->nb > (*index)->col_a->next->nb)
					swap_button(index, 1);
			}
			else if ((*index)->col_b->nb == lst_sort[0][half - 2] && (*index)->min_a > (*index)->max_b)
				push(index, 2);
			else if ((*index)->col_b->nb == lst_sort[0][0] && (*index)->len_b > 2)
			{
				push(index, 2);
				rotate(index, 1);
			}
			else if (big_position((*index)->col_b, *lst_sort, half, (*index)->len_b) >= 0)
				rotate(index, 2);
			else if (big_position((*index)->col_b, *lst_sort, half, (*index)->len_b) < 0)
				reverse_rot(index, 2);
			printf("je suis i == %d\n",lst_sort[0][half - 1]);
			half--;
			i++;
			if (i == 3)
				exit(EXIT_SUCCESS);
		}
		while ((*index)->last_a < (*index)->col_a->nb)
		{
			reverse_rot(index, 1);
		}
		half = (*index)->len_a;
	}
	exit(EXIT_SUCCESS);
	//mettre condition si il est desordre croissqnt
	return (1);
}
