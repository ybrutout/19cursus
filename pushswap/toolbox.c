/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:06:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/19 13:49:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_num *alst)
{
	t_num	*tmp;
	t_num	*tmp_tmp;

	if (!alst)
		return ;
	tmp = alst;
	while (tmp->next)
	{
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
	free(tmp);
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

t_col	*init_new_lst(t_num **col_a, t_num **col_b, int nb)
{
	t_col *index;

	index = malloc(sizeof(t_col));
	index->col_a = *col_a;
	index->col_b = *col_b;
	index->max = nb_max(col_a, nb);
	index->max_a = index->max;
	index->min = nb_min(col_a, nb);
	index->min_a = index->min;
	index->min_b = 0;
	index->max_b = 0;
	index->argc = nb;
	index->len_a = ft_lstsize(*col_a);
	index->len_b = ft_lstsize(*col_b);
	return(index);
}
