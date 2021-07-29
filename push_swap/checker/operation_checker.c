/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:57:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_num	*ch_swap(t_num *column)
{
	t_num	*tmp;
	t_num	*swap;

	tmp = column;
	swap = column->next;
	column->next = column->next->next;
	column = swap;
	swap->next = tmp;
	return (column);
}

void	ch_swap_button(t_col **index, int button)
{
	if (button == 1)
	{
		if ((*index)->col_a && (*index)->len_a > 1)
			(*index)->col_a = ch_swap((*index)->col_a);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && (*index)->len_b > 1)
			(*index)->col_b = ch_swap((*index)->col_b);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && (*index)->len_a > 1)
			(*index)->col_a = ch_swap((*index)->col_a);
		if ((*index)->col_b && (*index)->len_b > 1)
			(*index)->col_b = ch_swap((*index)->col_b);
	}
}

void	ch_push(t_col **index, int button)
{
	t_num	*tmp;

	if (button == 1)
	{
		if ((*index)->col_a)
		{
			tmp = (*index)->col_a;
			(*index)->col_a = (*index)->col_a->next;
			tmp->next = (*index)->col_b;
			(*index)->col_b = tmp;
		}
	}
	else if (button == 2)
	{
		if ((*index)->col_b)
		{
			tmp = (*index)->col_b;
			(*index)->col_b = (*index)->col_b->next;
			tmp ->next = (*index)->col_a;
			(*index)->col_a = tmp;
		}
	}
}

void	ch_rotate(t_col **index, int button)
{
	if (button == 1)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
			ch_rotate_bis(index, 1);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && ((*index)->col_b->next))
			ch_rotate_bis(index, 2);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
			ch_rotate_bis(index, 1);
		if ((*index)->col_b && ((*index)->col_b->next))
			ch_rotate_bis(index, 2);
	}
}

void	ch_reverse_rot(t_col **index, int button)
{
	int		len;

	if (button == 1)
	{
		if ((*index)->col_a && (*index)->col_a->next)
			ch_reverse_rott_biss(index, len, 1);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && (*index)->col_b->next)
			ch_reverse_rott_biss(index, len, 2);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && (*index)->col_a->next)
			ch_reverse_rott_biss(index, len, 1);
		if ((*index)->col_b && (*index)->col_b->next)
			ch_reverse_rott_biss(index, len, 2);
	}
}
