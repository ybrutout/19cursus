/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:06:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/25 13:36:53 by ybrutout         ###   ########.fr       */
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

t_col	*int_new_index(t_num **col_a, t_num **col_b, int nb)
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

int	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	while (lst_sort[0][i] && i < (argc - 1))
	{
		if (lst_sort[0][i] == lst_sort[0][i + 1] && (i + 1) < (argc - 1))
		{
			printf("a == %d\n b == %d\n", lst_sort[0][i], lst_sort[0][i + 1]);
			return (0);
		}
		else if (lst_sort[0][i] > lst_sort[0][i + 1] && (i + 1) < (argc - 1))
		{
			j = lst_sort[0][i + 1];
			lst_sort[0][i + 1] = lst_sort[0][i];
			lst_sort[0][i] = j;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}
