/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:44:43 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 16:56:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middlepoint(t_col **index, int **lst_sort)
{
	int		len;
	int		median;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 2);
	if (!*lst_sort)
		return (0);
	median = lst_sort[0][(len/2)];
	while (len > 0)
	{
		if ((*index)->col_a && (*index)->col_a->nb < median)
			push(index, 1);
		else
		{
			if ((*index)->col_b && ((*index)->col_b->nb < (*index)->last_b))
				rotate(index, 3);
			else
				rotate(index, 1);
		}
		len--;
	}
	return (1);
}

int	position(t_col **index, t_num *col, int len_col, int middle)
{
	int		len;
	int		tmp;
	int		tmp_op;
	int		sign;
	int		sign_tmp;
	t_num	*tmp_col;

	if (len_col < 3)
		return (0);
	tmp_col = col;
	len = 0;
	tmp = nb_max(&col, len_col);
	sign = 0;
	while (col)
	{
		if (tmp_col->nb == tmp)
			break;
		len++;
		tmp_col = tmp_col->next;
	}
	if (len > middle)
	{
		sign = -1;
		tmp_op = ((len_col - len) + 1);
	}
	else
		tmp_op = len + 1;
	if ((*index)->max_b < (*index)->col_a->nb)
	{
		len = 0;
		tmp = nb_second_max(&col, len_col, nb_max(&col, len_col));
		tmp_col = col;
		while (col)
		{
			if (tmp_col->nb == tmp)
				break;
			len++;
			tmp_col = tmp_col->next;
		}
		if (len > middle)
		{
			sign_tmp = -1;
			tmp = ((len_col - len) + 2);
		}
		else
		{
			sign_tmp = 0;
			tmp = len + 2;
		}
		if (tmp < tmp_op)
		{
			tmp_op = tmp;
			sign = sign_tmp;
		}
	}
	len = 0;
	tmp = nb_min(&col, len_col);
	tmp_col = col;
	while (col)
	{
		if (tmp_col->nb == tmp)
			break;
		len++;
		tmp_col = tmp_col->next;
	}
	if (len > middle)
	{
		sign_tmp = -1;
		tmp = ((len_col - len) + 3);
	}
	else
	{
		sign_tmp = 0;
		tmp = len + 3;
	}
	if (tmp < tmp_op)
	{
		sign = sign_tmp;
		tmp_op = tmp;
	}
	if (sign == -1)
		tmp_op = tmp_op * -1;
	return (tmp_op);
}

int	sorted(t_col **index, int **lst_sort)
{
	int	i;
	int	tests;

	tests = 0;
	if (ascending(&(*index)->col_a) == 1)
		return (1);
	while ((*index)->len_a > 2)
		middlepoint(index, lst_sort);
	if (ascending(&((*index)->col_a)) != 1)
		rotate(index, 1);
	while ((*index)->len_b != 0)
	{
		i = position(index, (*index)->col_b, (*index)->len_b, (((*index)->len_b) / 2));
		if ((*index)->col_b->nb == (*index)->max_b)
			push(&(*index), 2);
		else if ((*index)->col_b->nb == nb_second_max(&((*index)->col_b), (*index)->len_b, (*index)->max_b) && (*index)->max_b < (*index)->col_a->nb)
			push(&(*index), 2);
		else if ((*index)->col_b->nb == (*index)->min_b)
		{
			push(&(*index), 2);
			if (position(index, (*index)->col_b, (*index)->len_b, ((*index)->len_b)/2) <= (((*index)->len_b) / 2) && (*index)->col_b->nb != (*index)->max_b)
				rotate(&(*index), 3);
			else
				rotate(&(*index), 1);
		}
		else if (i < 0)
			reverse_rot(index, 2);
		else if (i > 0)
			rotate(index, 2);
		tests++;
		if (tests == 212)
			exit(EXIT_SUCCESS);
	}
	while ((*index)->last_a < (*index)->col_a->nb)
		reverse_rot(index, 1);
	return (1);
}
