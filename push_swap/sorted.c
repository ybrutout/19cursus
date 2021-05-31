/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:44:43 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/31 14:31:42 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middlepoint(t_col **index, int **lst_sort)
{
	int		len;
	int		median;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 2);
	if (!(*lst_sort))
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

int	position_for(t_num *col, int nb)
{
	t_num	*tmp_col;
	int		len;
	tmp_col = col;
	len = 0;
	while (tmp_col)
	{
		if (tmp_col->nb == nb)
			break;
		tmp_col = tmp_col->next;
		len++;
	}
	return (len);
}

int	position(t_col **index, int len_col, int middle, int button)
{
	int		oper;
	int		tmp;
	int		sign;
	int		tmp_sign;
	t_num	*tmp_col;

	if (len_col < 3)
		return (0);
	if (button == 1)
		tmp_col = (*index)->col_a;
	else if (button == 2)
		tmp_col = (*index)->col_b;
	sign = 1;
	oper = (position_for(tmp_col, nb_max(&tmp_col, len_col)) + 1);
	if (oper > middle)
	{
		oper = (len_col - oper) + 2;
		sign = -1;
	}
	if ((*index)->col_a->nb > (*index)->max_b)
	{
		tmp = (position_for(tmp_col, nb_second_max(&tmp_col, len_col, nb_max(&tmp_col, len_col))) + 2);
		tmp_sign = 1;
		if (tmp > middle)
		{
			tmp_sign = -1;
			tmp = (len_col - tmp) + 4;
		}
		if (tmp < oper)
		{
			sign = tmp_sign;
			oper = tmp;
		}
	}
	tmp = (position_for(tmp_col,nb_min(&tmp_col, len_col)) + 3);
	tmp_sign = 1;
	if (tmp > middle)
	{
		tmp_sign = -1;
		tmp = (len_col - tmp) + 6;
	}
	if (tmp < oper)
	{
		sign = tmp_sign;
		oper = tmp;
	}
	if (sign == -1)
		oper = oper * sign;
	return (oper);
}

int	sorted(t_col **index, int **lst_sort)
{
	int	i;
	int	tests;

	tests = 0;
	if (ascending(&(*index)->col_a) == 1)
		return (1);
	while ((*index)->len_a > 2)
		if (middlepoint(index, lst_sort) == 0)
			return(ft_error(*index, *lst_sort, 5));
	if (ascending(&((*index)->col_a)) != 1)
		rotate(index, 1);
	while ((*index)->len_b > 0)
	{
		i = position(index, (*index)->len_b, (((*index)->len_b) / 2), 2);
		if ((*index)->col_b->nb == (*index)->max_b)
			push(&(*index), 2);
		else if ((*index)->col_b->nb == nb_second_max(&((*index)->col_b), (*index)->len_b, (*index)->max_b) && (*index)->max_b < (*index)->col_a->nb)
			push(&(*index), 2);
		else if ((*index)->col_b->nb == (*index)->min_b)
		{
			push(&(*index), 2);
			if (position(index, (*index)->len_b, ((*index)->len_b)/2, 2) <= (((*index)->len_b) / 2) && (*index)->col_b->nb != (*index)->max_b)
				rotate(&(*index), 3);
			else
				rotate(&(*index), 1);
		}
		else if (i < 0)
			reverse_rot(index, 2);
		else if (i >= 0)
			rotate(index, 2);
	/*	tests++;
		if (tests == 256)
			exit(EXIT_SUCCESS);*/
	}
	while ((*index)->last_a < (*index)->col_a->nb)
		reverse_rot(index, 1);
	return (1);
}
