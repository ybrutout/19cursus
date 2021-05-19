/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:26:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/19 14:17:13 by ybrutout         ###   ########.fr       */
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

int	median(t_num **col_a, t_num **col_b, int **lst_sort, int nb)
{
	t_col	*index;

	index = init_new_lst(col_a, col_b, nb);
	if ((ascending(col_a)) == 1)
		return (1);
	free(index);
	return (1);
}

//tests pour savoir si index est bien initié.
/*	printf("col_a == %p %p\n", *col_a, index->col_a);
	printf("col_b == %p %p\n", *col_b, index->col_b);
	printf("max == %d\n", index->max);
	printf("min == %d\n", index->min);
	printf("max_a == %d\n", index->max_a);
	printf("max_b == %d\n", index->max_b);
	printf("min_a == %d\n", index->min_a);
	printf("min_b == %d\n", index->min_b);
	printf("argc == %d\n", index->argc);
	printf("max == %d\n", index->len_a);
	printf("min == %d\n", index->len_b);*/
