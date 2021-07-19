/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:12:52 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/19 16:03:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_not_decreasing(t_col **index, int len_b)
{
	int	i;

	i = position(index, (*index)->col_b, len_b, ((len_b) / 2));
	if ((*index)->col_b->nb == (*index)->max_b)
	{
		push(index, 2);
		if ((*index)->col_a->next->nb < (*index)->col_a->nb)
			swap_button(index, 1);
	}
	else if ((*index)->col_b->nb == nb_second_max(&((*index)->col_b), \
	len_b, (*index)->max_b) && (*index)->max_b < (*index)->col_a->nb)
		push(index, 2);
	else if ((*index)->col_b->nb == (*index)->min_b)
	{
		push(index, 2);
		rotate(index, 1);
	}
	else if (i < 0)
		reverse_rot(index, 2);
	else if (i > 0)
		rotate(index, 2);
}

void	sorted_bis(t_col **index)
{
	while ((*index)->len_b != 0)
	{
		if ((*index)->col_a->nb > (*index)->col_b->nb)
			push(index, 2);
		else
		{
			push(index, 2);
			swap_button(index, 1);
		}
	}
}

int	sorted(t_col **index, int **lst_sort)
{
	middlepoint_first(index, lst_sort);
	while ((ascending((*index)->col_a, (*index)->len_a) == 0) \
	&& (*index)->len_a > 2)
		middlepoint(index, lst_sort);
	if (ascending((*index)->col_a, (*index)->len_a) != 1)
		rotate(index, 1);
	while (decreasing((*index)->col_b, (*index)->len_b) == 0 \
	|| (*index)->len_b == 0)
		is_not_decreasing(index, (*index)->len_b);
	if ((*index)->len_b > 0)
		sorted_bis(index);
	while ((*index)->last_a < (*index)->col_a->nb)
		reverse_rot(index, 1);
	return (1);
}
