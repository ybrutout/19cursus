/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:07:05 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 11:24:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num 	*swap(t_num *column)
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
		if ((*index)->col_a->nb > (*index)->col_a->next->nb)
			swap_button(index, 1);
	}
}

void	rotate(t_col **index, int button)
{
	t_num	*tmp;

	if (button == 1)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
		{
			tmp = (*index)->col_a;
			(*index)->col_a = (*index)->col_a->next;
			tmp->next = NULL;
			(*index)->col_a = ft_lstadd_back((*index)->col_a, tmp);
		}
		ft_write(6, index);
	}
	else if (button == 2)
	{
		if ((*index)->col_b && ((*index)->col_b->next))
		{
			tmp = (*index)->col_b;
			(*index)->col_b = (*index)->col_b->next;
			tmp->next = NULL;
			(*index)->col_b = ft_lstadd_back((*index)->col_b, tmp);
		}
		ft_write(7, index);
	}
	else if (button == 3)
	{
		if ((*index)->col_a && ((*index)->col_a->next))
		{
			tmp = (*index)->col_a;
			(*index)->col_a = (*index)->col_a->next;
			tmp->next = NULL;
			(*index)->col_a = ft_lstadd_back((*index)->col_a, tmp);
		}
		if ((*index)->col_b && ((*index)->col_b->next))
		{
			tmp = (*index)->col_b;
			(*index)->col_b = (*index)->col_b->next;
			tmp->next = NULL;
			(*index)->col_b = ft_lstadd_back((*index)->col_b, tmp);
		}
		ft_write(8, index);
	}
}

void	reverse_rot(t_col **index, int button)
{
	t_num	*start;
	t_num	*tmp;
	int		len;

	if (button == 1)
	{
		len = ft_lstsize((*index)->col_a);
		if ((*index)->col_a && (*index)->col_a->next)
		{
			start = (*index)->col_a;
			while (len-- != 2)
				start = start->next;
			tmp = start->next;
			start->next = NULL;
			tmp->next = (*index)->col_a;
			(*index)->col_a = tmp;
		}
		ft_write(9, index);
	}
	else if (button == 2)
	{
		len = ft_lstsize((*index)->col_b);
		if ((*index)->col_b && (*index)->col_b->next)
		{
			start = (*index)->col_b;
			while (len-- != 2)
				start = start->next;
			tmp = start->next;
			start->next = NULL;
			tmp->next = (*index)->col_b;
			(*index)->col_b = tmp;
		}
		ft_write(10, index);
	}
	else if (button == 3)
	{
		len = ft_lstsize((*index)->col_a);
		if ((*index)->col_a && (*index)->col_a->next)
		{
			start = (*index)->col_a;
			while (len-- != 2)
				start = start->next;
			tmp = start->next;
			start->next = NULL;
			tmp->next = (*index)->col_a;
			(*index)->col_a = tmp;
		}
		len = ft_lstsize((*index)->col_b);
		if ((*index)->col_b && (*index)->col_b->next)
		{
			start = (*index)->col_b;
			while (len-- != 2)
				start = start->next;
			tmp = start->next;
			start->next = NULL;
			tmp->next = (*index)->col_b;
			(*index)->col_b = tmp;
		}
		ft_write(11, index);
	}
}
