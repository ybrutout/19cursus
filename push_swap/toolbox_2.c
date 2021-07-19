/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:57:37 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/19 15:21:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decreasing(t_num *col_b, int len)
{
	t_num	*tmp;
	int		i;

	tmp = col_b;
	while (len != 0)
	{
		i = tmp->nb;
		if (tmp->next && (i < tmp->next->nb))
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

int	ascending(t_num *col_a, int len)
{
	t_num	*tmp;
	int		i;

	tmp = col_a;
	while (len != 0)
	{
		i = tmp->nb;
		if (tmp->next && (i > tmp->next->nb))
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

int	nb_min(t_num **col_a, int len)
{
	t_num	*tmp;
	int		min;

	min = (*col_a)->nb;
	tmp = *col_a;
	while (len != 0)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
		len--;
	}
	return (min);
}

int	nb_max(t_num **col_a, int len)
{
	t_num	*tmp;
	int		max;

	max = (*col_a)->nb;
	tmp = *col_a;
	while (len != 0)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
		len--;
	}
	return (max);
}

int	nb_second_max(t_num **col, int len, int max)
{
	t_num	*tmp;
	int		tmp_max;

	if ((*col)->nb != max)
		tmp_max = (*col)->nb;
	else
		tmp_max = (*col)->next->nb;
	tmp = *col;
	while (len != 0)
	{
		if (tmp_max < tmp->nb && (tmp->nb != max))
			tmp_max = tmp->nb;
		tmp = tmp->next;
		len--;
	}
	return (tmp_max);
}
