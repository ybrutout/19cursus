/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:24:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/19 13:18:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_for(t_num *col, int nb)
{
	t_num	*tmp_col;
	int		len;

	tmp_col = col;
	len = 0;
	while (tmp_col)
	{
		if (tmp_col->nb == nb)
			break ;
		tmp_col = tmp_col->next;
		len++;
	}
	return (len);
}

int	position_bis(t_col **index, int middle, t_num *tmp_col, int len)
{
	int	tmp;
	int	tmp_sign;
	int	oper;
	int	sign;

	oper = (position_for(tmp_col, nb_max(&tmp_col, len)) + 1);
	if (oper > middle)
	{
		oper = (len - oper) + 2;
		sign = -1;
	}
	if ((*index)->col_a->nb > (*index)->max_b)
	{
		tmp = (position_for(tmp_col, nb_second_max(&tmp_col, len, \
		nb_max(&tmp_col, len))) + 2);
		tmp_sign = 1;
		if (tmp < oper)
		{
			sign = tmp_sign;
			oper = tmp;
		}
	}
	if (sign < 0)
		oper = oper * -1;
	return (oper);
}

int	position(t_col **index, t_num *col, int len, int middle)
{
	int	tmp;
	int	tmp_sign;
	int	oper;
	int	sign;

	sign = 1;
	oper = position_bis(index, middle, col, len);
	if (oper < 0)
	{
		oper *= -1;
		sign = -1;
	}
	tmp = (position_for(col, nb_min(&col, len)) + 3);
	tmp_sign = 1;
	if (tmp > middle)
	{
		tmp_sign = -1;
		tmp = (len - tmp) + 6;
	}
	if (tmp < oper)
	{
		sign = tmp_sign;
		oper = tmp;
	}
	return (oper * sign);
}
