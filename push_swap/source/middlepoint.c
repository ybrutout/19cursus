/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlepoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:27:51 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 11:09:19 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	mdpnt_check(t_num *col, int median, int len, int sign)
{
	t_num	*tmp;

	tmp = col;
	if (sign == 1)
	{
		while (len != 0)
		{
			if (tmp->nb < median)
				return (0);
			len--;
			tmp = tmp->next;
		}
	}
	else if (sign == 2)
	{
		while (len != 0)
		{
			if (tmp->nb > median)
				return (0);
			len--;
			tmp = tmp->next;
		}
	}
	return (1);
}

int	mdpnt_first_bis(t_col **index, int median, int pivot)
{
	if ((*index)->col_a && (*index)->col_a->nb < median)
	{
		if ((mdpnt_check((*index)->col_a, pivot, (*index)->len_a, 2)) == 1)
			while ((*index)->col_b && (*index)->len_b > 2 \
			&& (*index)->col_b->nb < pivot)
				rotate(index, 2);
		push(index, 1);
	}
	else
	{
		if ((*index)->len_b > 2 && (*index)->col_b->nb < pivot \
		&& (*index)->col_b->nb < (*index)->col_b->next->nb)
			rotate(index, 3);
		else
			rotate(index, 1);
	}
	return (1);
}

int	middlepoint_first(t_col **index, int **lst_sort)
{
	int		median;
	int		pivot;

	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 2);
	if (!(*lst_sort))
		ft_error_message(index, 1);
	median = lst_sort[0][(((*index)->len_a) / 2)];
	pivot = lst_sort[0][((*index)->len_a / 2)];
	while ((mdpnt_check((*index)->col_a, median, (*index)->len_a, 1)) == 0)
		mdpnt_first_bis(index, median, pivot);
	if ((*index)->col_b->nb < pivot)
		rotate(index, 2);
	return (1);
}

int	mdpnt_bis(t_col **index, int len, int median)
{
	t_num	*tmp;
	int		last_a;

	len = (*index)->len_a;
	tmp = (*index)->col_a;
	last_a = (*index)->last_a;
	if (ascending(tmp, len) == 1 && (*index)->min_a > (*index)->max_b)
		return (2);
	if (tmp && tmp->nb < median)
		push(index, 1);
	else if (last_a < median && last_a < tmp->nb && last_a < tmp->next->nb)
	{
		if ((*index)->len_b > 0 && (*index)->last_b > (*index)->col_b->nb)
			reverse_rot(index, 3);
		else
			reverse_rot(index, 1);
	}
	else
	{
		if ((*index)->col_b && ((*index)->col_b->nb < (*index)->last_b))
			rotate(index, 3);
		else
			rotate(index, 1);
	}
	return (1);
}

int	middlepoint(t_col **index, int **lst_sort)
{
	int		len;
	int		median;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, len, 2);
	if (!(*lst_sort))
		ft_error_message(index, 1);
	median = lst_sort[0][(len / 2)];
	while ((mdpnt_check((*index)->col_a, median, (*index)->len_a, 1)) == 0)
	{
		if (mdpnt_bis(index, len, median) == 2)
			break ;
	}
	return (1);
}
