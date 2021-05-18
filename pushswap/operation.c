/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:38:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/18 11:48:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void 	swap(t_num **column)
{
	t_num	*tmp;
	t_num	*swap;

	tmp = *column;
	swap = (*column)->next;
	(*column)->next = (*column)->next->next;
	*column = swap;
	swap->next = tmp;
}

void	swap_button(t_num **col_a, t_num **col_b, int button)
{
	if ((*col_a)->next)
		swap(col_a);
	if (button == 1)
		write(1, "sa\n", 3);
	else if (button == 2)
		write(1, "sb\n", 3);
	else if (button == 3)
	{
		if ((*col_b)->next)
			swap(col_b);
		write(1, "ss\n", 3);
	}
}

void	push(t_num **col_a, t_num **col_b, int button)
{
	t_num	*tmp;

	if ((*col_b)->next)
	{
		tmp = *col_b;
		*col_b = (*col_b)->next;
		tmp ->next = *col_a;
		*col_a = tmp;
	}
	if (button == 1)
		write(1, "pa\n", 3);
	else if (button == 2)
		write(1, "pb\n", 3);
}

void	rotate(t_num **col_a, t_num **col_b, int button)
{
	t_num *tmp;

	if ((*col_a)->next && (*col_a)->next->next)
	{
		tmp = *col_a;
		*col_a = (*col_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(col_a, tmp);
	}
	if (button == 1)
		write(1, "ra\n", 3);
	else if (button == 2)
		write(1, "rb\n", 3);
	else if (button == 3)
	{
		rotate(col_b, col_a, 4);
		write(1, "rr\n", 4);
	}
}
