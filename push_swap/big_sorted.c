/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:08:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/07 15:58:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_the_pivot(int **lst_sort, int len, t_col **index, t_num *col)
{
	int	*pivot;

	*lst_sort = nw_lst_order(&col, *lst_sort, len, 1);
	pivot = malloc(sizeof(int) * 5);
	if (!pivot)
		return(NULL);
	len = len / 5;
	pivot[0] = lst_sort[0][len];
	pivot[1] = lst_sort[0][len * 2];
	pivot[2] = lst_sort[0][len * 3];
	pivot[3] = lst_sort[0][len * 4];
	pivot[4] = lst_sort[0][(len * 5) - 1];
	return (pivot);
}

int	empty_a(t_col **index, int **lst_sort)
{
	int	*pivot;
	int	len;
	int i;
	int	nb;

	len = (*index)->len_a;
	pivot = find_the_pivot(lst_sort, (*index)->len_a, index, (*index)->col_a);
	if (!pivot)
		return (0);
	nb = 0;
	i = 0;
	while ((*index)->len_a > 0)
	{
		while (i < (len / 5))
		{
			if ((*index)->col_a->nb <= pivot[nb])
			{
				push(index, 1);
				i++;
			}
			else
				rotate(index, 1);
		}
		i = 0;
		nb++;
	}
	free(pivot);
	return(1);
}

int		find_the_divide(int len)
{
	int i;

	i = 0;
	while (len >= 2)
	{
		if (len % 2)
		{
			len = (len / 2) + 1;
			i++;
		}
		else
		{
			len = len / 2;
			i++;
		}
	}
	return (i);
}

int		*find_the_fulcrum(t_col **index, int **lst_sort, int len, int knob)
{
	int i;
	int	*fulcrum;
	int j;

	i = find_the_divide(len);
	fulcrum = malloc(sizeof(int) * (i * 2));
	i = 0;
	j = 0;
	while (len >= 2)
	{
		if (len % 2)
		{
			len = (len / 2);
			fulcrum[i] = lst_sort[0][((*index)->len_b) - len - 1];
			fulcrum[i++] = len;
			i++;
		}
		else
		{
			len = len / 2;
			fulcrum[i] = lst_sort[0][((*index)->len_b) - len - 1];
			fulcrum[i++] = len;
			i++;
		}
	}
	while (j < 10)
	{
		printf("fulcrum %d == %d\n", j, fulcrum[j]);
		j++;
		printf("fulcrum %d == %d\n", j, fulcrum[j]);
		j++;
	}
	exit(EXIT_SUCCESS);
}

int		ping_sort(t_col **index, int **lst_sort, int pivot, int len_pivot)
{
	int	i;
	int	*fulcrum;

	i = 0;
	fulcrum = find_the_fulcrum(index, lst_sort, len_pivot, 0);
	exit(EXIT_SUCCESS);
	while ((*index)->max_b >= pivot)
	{
		while (i < len_pivot)
		{
			if ((*index)->col_b->nb > pivot)
			{
				i++;
				push(index, 1);
			}
			else
				rotate(index, 2);
		}
	}
	free(fulcrum);
	return (1);
}

int		quick_sort(t_col **index, int **lst_sort)
{
	int *pivot;
	int	len_pivot;
	int	i;
	int ret;

	pivot = find_the_pivot(lst_sort, (*index)->len_b, index, (*index)->col_b);
	if (!pivot)
		return (0);
	len_pivot = ((*index)->len_b) / 5;
	i = 4;
	while (i != 0 && (*index)->len_b != 0)
	{
		ret = ping_sort(index, lst_sort, pivot[i], len_pivot);
		if (!ret)
			return (0);
		i--;
	}
	free(pivot);
	return (1);
}

int 	big_sorted(t_col **index, int **lst_sort)
{
	int ret;

	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 1);
	ret = empty_a(index, lst_sort);
	if (ret == 0)
		return(0);
	ret = quick_sort(index, lst_sort);
	if (ret == 0)
		return(0);
	return (1);
}
