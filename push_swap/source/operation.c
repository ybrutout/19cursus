/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:07:05 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:57:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_num	*swap(t_num *column)
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

void	swap_button(t_col **index, int button)
{
	if (button == 1)
	{
		if ((*index)->col_a && (*index)->len_a > 1)
			(*index)->col_a = swap((*index)->col_a);
		ft_write(1, index);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && (*index)->len_b > 1)
			(*index)->col_b = swap((*index)->col_b);
		ft_write(2, index);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && (*index)->len_a > 1)
			(*index)->col_a = swap((*index)->col_a);
		if ((*index)->col_b && (*index)->len_b > 1)
			(*index)->col_b = swap((*index)->col_b);
		ft_write(3, index);
	}
}

void	push(t_col **index, int button)
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
		ft_write(5, index);
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
		ft_write(4, index);
	}
}

void	rotate(t_col **index, int button)
{
	if (button == 1)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
			rotate_bis(index, 1);
		ft_write(6, index);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && ((*index)->col_b->next))
			rotate_bis(index, 2);
		ft_write(7, index);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
			rotate_bis(index, 1);
		if ((*index)->col_b && ((*index)->col_b->next))
			rotate_bis(index, 2);
		ft_write(8, index);
	}
}

void	reverse_rot(t_col **index, int button)
{
	int		len;

	if (button == 1)
	{
		if ((*index)->col_a && (*index)->col_a->next)
			reverse_rott_biss(index, len, 1);
		ft_write(9, index);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && (*index)->col_b->next)
			reverse_rott_biss(index, len, 2);
		ft_write(10, index);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && (*index)->col_a->next)
			reverse_rott_biss(index, len, 1);
		if ((*index)->col_b && (*index)->col_b->next)
			reverse_rott_biss(index, len, 2);
		ft_write(11, index);
	}
}
