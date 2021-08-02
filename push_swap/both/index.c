/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:09:30 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 09:22:27 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	last_nb(t_num *col, int	len)
{
	t_num	*tmp;
	int		ret;

	tmp = col;
	while (len != 0)
	{
		ret = tmp->nb;
		tmp = tmp->next;
		len--;
	}
	return (ret);
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

void	change_index(t_col **index)
{
	int	tmp;

	tmp = ft_lstsize((*index)->col_a);
	(*index)->len_a = tmp;
	tmp = ft_lstsize((*index)->col_b);
	(*index)->len_b = tmp;
	if ((*index)->len_a > 0)
	{
		tmp = nb_max(&((*index)->col_a), (*index)->len_a);
		(*index)->max_a = tmp;
		tmp = nb_min(&((*index)->col_a), (*index)->len_a);
		(*index)->min_a = tmp;
	}
	if ((*index)->len_b > 0)
	{
		tmp = nb_max(&((*index)->col_b), (*index)->len_b);
		(*index)->max_b = tmp;
		tmp = nb_min(&((*index)->col_b), (*index)->len_b);
		(*index)->min_b = tmp;
	}
	tmp = last_nb((*index)->col_a, (*index)->len_a);
	(*index)->last_a = tmp;
	tmp = last_nb((*index)->col_b, (*index)->len_b);
	(*index)->last_b = tmp;
}

t_col	*int_new_index(int nb, char **argv)
{
	t_col	*index;

	index = malloc(sizeof(t_col));
	if (!index)
		ft_error_message(&index, -1);
	index->col_a = NULL;
	index->col_b = NULL;
	index->max = 0;
	index->max_a = 0;
	index->min = 0;
	index->min_a = 0;
	index->min_b = 0;
	index->max_b = 0;
	index->argc = nb;
	index->len_a = 0;
	index->len_b = 0;
	index->last_a = 0;
	index->last_b = 0;
	index->stack = 0;
	if (parsing(argv, &index) != 1)
	{
		free(index);
		return (NULL);
	}
	return (index);
}
