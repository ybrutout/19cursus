/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:55:38 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 13:06:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decreasing(t_num **col_b)
{
	t_num	*tmp;
	int		i;

	tmp = *col_b;
	while (tmp)
	{
		i = tmp->nb;
		if (tmp->next && (i < tmp->next->nb))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ascending(t_num **col_a)
{
	t_num	*tmp;
	int		i;

	tmp = *col_a;
	while (tmp)
	{
		i = tmp->nb;
		if (tmp->next && (i > tmp->next->nb))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		nb_min(t_num **col_a, int nb)
{
	t_num	*tmp;
	int		min;

	min = (*col_a)->nb;
	tmp = *col_a;
	while (nb != 0)
	{
		if(min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
		nb--;
	}
	return (min);
}

int		nb_max(t_num **col_a, int nb)
{
	t_num	*tmp;
	int		max;

	max = (*col_a)->nb;
	tmp = *col_a;
	while (nb != 0)
	{
		if(max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
		nb--;
	}
	return (max);
}

int		nb_second_max(t_num **col_a, int nb, int max)
{
	t_num	*tmp;
	int		tmp_max;

	if ((*col_a)->nb != max)
		tmp_max = (*col_a)->nb;
	else
		tmp_max = (*col_a)->next->nb;
	tmp = *col_a;
	while (nb != 0 && tmp->next)
	{
		if(tmp_max < tmp->nb && (tmp->nb != max))
			tmp_max = tmp->nb;
		tmp = tmp->next;
		nb--;
	}
	return (tmp_max);
}
