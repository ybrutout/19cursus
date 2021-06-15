/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:12:52 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/15 16:02:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middlepoint_check(t_num *col, int median, int len, int sign)
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

int	middlepoint_first(t_col **index, int **lst_sort)
{
	int		len;
	int		median;
	int		pivot;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, len, 2);
	if (!(*lst_sort))
		return (0);
	median = lst_sort[0][(len/2)];
	pivot = lst_sort[0][(median/2)];
	while ((middlepoint_check((*index)->col_a, median, (*index)->len_a, 1)) == 0)
	{
		if ((*index)->col_a && (*index)->col_a->nb < median)
		{
			if ((middlepoint_check((*index)->col_a, pivot, (*index)->len_a, 2)) == 1)
				while ((*index)->col_b && (*index)->len_b > 2 && (*index)->col_b->nb < pivot)
					rotate(index, 2);
			push(index, 1);
		}
		/*else if ((*index)->last_a < median && (*index)->last_a < (*index)->col_a->nb && (*index)->last_a < (*index)->col_a->next->nb)
				reverse_rot(index, 1);*/
		else
		{
			if ((*index)->len_b > 2 && (*index)->col_b->nb < pivot && (*index)->col_b->nb < (*index)->col_b->next->nb)
				rotate(index, 3);
			else
				rotate(index, 1);
		}
	}
	if ((*index)->col_b->nb < pivot)
		rotate(index, 2);
	return (1);
}

int	middlepoint(t_col **index, int **lst_sort)
{
	int		len;
	int		median;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, len, 2);
	if (!(*lst_sort))
		return (0);
	median = lst_sort[0][(len/2)];
	while ((middlepoint_check((*index)->col_a, median, (*index)->len_a, 1)) == 0)
	{
		if (ascending((*index)->col_a, (*index)->len_a) == 1)
		{
			//write(1, "je suis la\n", 11);
			return (1);
		}
		if ((*index)->col_a && (*index)->col_a->nb < median)
			push(index, 1);
		else if ((*index)->last_a < median && (*index)->last_a < (*index)->col_a->nb /*&& (*index)->last_a < (*index)->col_a->next->nb*/)
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

	if (middlepoint_first(index, lst_sort) == 0)
		return (0);
	while ((ascending((*index)->col_a, (*index)->len_a) == 0) && (*index)->len_a > 2)
	{
		if (middlepoint(index, lst_sort) == 0)
			return(0);
	}
	if (ascending((*index)->col_a, (*index)->len_a) != 1)
		rotate(index, 1);
	while (decreasing((*index)->col_b, (*index)->len_b) == 0 || (*index)->len_b == 0)
	{
		i = position(index, (*index)->len_b, (((*index)->len_b) / 2), 2);
		if ((*index)->col_b->nb == (*index)->max_b)
		{
			push(index, 2);
			if ((*index)->col_a->next->nb < (*index)->col_a->nb)
				swap_button(index, 1);
		}
		else if ((*index)->col_b->nb == nb_second_max(&((*index)->col_b), (*index)->len_b, (*index)->max_b) && (*index)->max_b < (*index)->col_a->nb)
			push(index, 2);
		else if ((*index)->col_b->nb == (*index)->min_b)
		{
			push(index, 2);
			if (position(index, (*index)->len_b, ((*index)->len_b)/2, 2) <= (((*index)->len_b) / 2) && (*index)->col_b->nb != (*index)->max_b)
				rotate(index, 3);
			else
				rotate(index, 1);
		}
		else if (i < 0)
			reverse_rot(index, 2);
		else if (i > 0)
			rotate(index, 2);
	}
	if ((*index)->len_b > 0)
		while ((*index)->len_b != 0)
		{
			if ((*index)->col_a->nb > (*index)->col_b->nb)
				push(index, 2);
			else
			{
				push(index, 2);
				swap_button(index, 1);
			}
		}
	while ((*index)->last_a < (*index)->col_a->nb)
		reverse_rot(index, 1);
	return (1);
}
