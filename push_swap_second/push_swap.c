/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:48:00 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 14:24:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ind	*int_new_index(int nb, int **lst_sort)
{
	t_ind *index;

	index = malloc(sizeof(t_ind));
	if (!index)
		return(ft_error(&index, lst_sort, 1, 0));
	index->col_a = NULL;
	index->col_b = NULL;
	index->max = 0;
	index->max_a = 0;
	index->min = 0;
	index->min_a = 0;
	index->min_b = 0;
	index->max_b = 0;
	index->argc = nb - 1;
	index->len_a = 0;
	index->len_b = 0;
	index->last_a = 0;
	index->last_b = 0;
	index->stack = 0;
	return(index);
}

int	main(int argc, char **argv)
{
	t_ind 	*indx;
	int		*lst_sort;

	indx = int_new_index(argc, lst_sort);
	if (!indx)
		return(0);
	lst_sort = malloc (sizeof(int));
	if (!lst_sort)
	{
		free(indx)
		return(ft_error(indx, lst_sort, 0, 0))
	}
	if (is_a_good_files(argv, &indx, &lst_sort) == 0)
		return (0);
}
