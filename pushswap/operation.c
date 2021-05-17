/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:38:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/17 15:54:57 by ybrutout         ###   ########.fr       */
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
