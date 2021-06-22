/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:43:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/22 16:39:56 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_five_hundred(t_col **index, int **lst_sort)
{
	int	half;
	int	*lst;

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
	while (decreasing((*index)->col_b, (*index)->len_b) == 0 && (*index)->len_b > 0)
	{
		while (half != 0)
		{
			
		}
		half = (*index)->len_a;
	}
	//mettre condition si il est desordre croissqnt
	return (1);
}
