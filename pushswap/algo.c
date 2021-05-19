/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:26:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/19 16:27:21 by ybrutout         ###   ########.fr       */
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

int	*nw_lst_order(t_num **col, int *lst_new, int len)
{
	int		*tmp;
	t_num	*tmp_col;
	int 	i;

	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		return (NULL);
	i = 0;
	if (*col)
	{
		tmp_col = *col;
			while (tmp_col)
		{
			tmp[i++] = tmp_col->nb;
			tmp_col = tmp_col->next;
		}
	}
	ft_order(&tmp, len);
	free(lst_new);
	return (tmp);
}

int	median(t_num **col_a, t_num **col_b, int **lst_sort, int nb)
{
	t_col	*index;
	int		median;
	int		len;
	t_num	*nb_tmp;
	t_num	*nb_tmp_b;
	int		i;

	i = 0;
	index = init_new_lst(col_a, col_b, nb);
	if ((ascending(col_a)) == 1)
	{
		free(index);
		return (1);
	}
	while (index->len_a > 2)
	{
		index->len_a = ft_lstsize(*col_a);
		len = index->len_a;
		*lst_sort = nw_lst_order(col_a, *lst_sort, index->len_a);
		median = lst_sort[0][(len/2)];
		while ((*lst_sort)[i])
			printf("lst == %d\n", (*lst_sort)[i++]);
		printf("len == %d\n", len/2);
		printf("median == %d\n", median);
		while (len > 0)
		{
			if ((*col_a)->nb < median)
				push(col_a, col_b, 2);
			else
				rotate(col_a, col_b, 1);
			len--;
		}
		nb_tmp = *col_a;
		nb_tmp_b = *col_b;
		while (nb_tmp)
		{
			printf("lst_a == %d\n", nb_tmp->nb);
			nb_tmp = nb_tmp->next;
		}
		while (nb_tmp_b)
		{
			printf("lst_b == %d\n", nb_tmp_b->nb);
			nb_tmp_b = nb_tmp_b->next;
		}
		printf("index->len_a == %d\n", index->len_a);
		printf("median == %d\n", median);
	}
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
