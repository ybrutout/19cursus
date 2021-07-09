/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:59:34 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/09 13:52:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_3(t_col **index)
{
	int	pos_min;
	int	pos_max;

	pos_min = position_for((*index)->col_a, (*index)->min_a);
	pos_max = position_for((*index)->col_a, (*index)->max_a);
	if (pos_min == 1 && pos_max == 2)
		swap_button(index, 1);
	else if (pos_min == 2 && pos_max == 0)
	{
		swap_button(index, 1);
		reverse_rot(index, 1);
	}
	else if (pos_min == 1 && pos_max == 0)
		rotate(index, 1);
	else if (pos_min == 0 && pos_max == 1)
	{
		swap_button(index, 1);
		rotate(index, 1);
	}
	else if (pos_min == 2 && pos_max == 1)
		reverse_rot(index, 1);
}

void	sorted_5_bis(t_col **index, int nxt_max, int middle)
{
	if ((*index)->col_a->nb != nxt_max && (*index)->col_a->nb != middle)
		push(index, 1);
	else
	{
		if ((*index)->col_a->next->nb == nxt_max || \
		(*index)->col_a->next->nb == middle)
			reverse_rot(index, 1);
		else
			rotate(index, 1);
	}
}

void	sorted_5(t_col **index, int **lst_sort)
{
	int	nxt_max;
	int	middle;
	int	argc;

	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 2);
	argc = (*index)->argc;
	nxt_max = lst_sort[0][argc - 2];
	middle = lst_sort[0][argc - 3];
	while ((*index)->len_a != 3)
		sorted_5_bis(index, nxt_max, middle);
	sorted_3(index);
	while ((*index)->len_b != 0)
	{
		push(index, 2);
		if ((*index)->col_a->nb == (*index)->max_a)
			rotate(index, 1);
		else if ((*index)->col_a->nb > (*index)->col_a->next->nb)
			swap_button(index, 1);
	}
}
