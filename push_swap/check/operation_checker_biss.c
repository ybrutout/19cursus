/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checker_biss.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:02:42 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 14:59:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ch_rotate_bis(t_col **index, int nb)
{
	t_num	*tmp;

	if (nb == 1)
	{
		tmp = (*index)->col_a;
		(*index)->col_a = (*index)->col_a->next;
		tmp->next = NULL;
		(*index)->col_a = ft_lstadd_back((*index)->col_a, tmp);
	}
	else
	{
		tmp = (*index)->col_b;
		(*index)->col_b = (*index)->col_b->next;
		tmp->next = NULL;
		(*index)->col_b = ft_lstadd_back((*index)->col_b, tmp);
	}
}

void	ch_reverse_rott_biss(t_col **index, int len, int nb)
{
	t_num	*start;
	t_num	*tmp;

	if (nb == 1)
	{
		len = ft_lstsize((*index)->col_a);
		start = (*index)->col_a;
		while (len-- != 2)
			start = start->next;
		tmp = start->next;
		start->next = NULL;
		tmp->next = (*index)->col_a;
		(*index)->col_a = tmp;
	}
	else
	{
		len = ft_lstsize((*index)->col_b);
		start = (*index)->col_b;
		while (len-- != 2)
			start = start->next;
		tmp = start->next;
		start->next = NULL;
		tmp->next = (*index)->col_b;
		(*index)->col_b = tmp;
	}
}

void	ft_operation(t_col **index, int nb)
{
	if (nb == 1)
		ch_swap_button(index, 1);
	else if (nb == 2)
		ch_swap_button(index, 2);
	else if (nb == 3)
		ch_swap_button(index, 3);
	else if (nb == 4)
		ch_push(index, 2);
	else if (nb == 5)
		ch_push(index, 1);
	else if (nb == 6)
		ch_rotate(index, 1);
	else if (nb == 7)
		ch_rotate(index, 2);
	else if (nb == 8)
		ch_rotate(index, 3);
	else if (nb == 9)
		ch_reverse_rot(index, 1);
	else if (nb == 10)
		ch_reverse_rot(index, 2);
	else if (nb == 11)
		ch_reverse_rot(index, 3);
	change_index(index);
}
