/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:08:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/08 11:48:14 by ybrutout         ###   ########.fr       */
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

int		*find_the_fulcrum(t_col **index, int **lst_sort, int len)
{
	int i;
	int	*fulcrum;
	int	tmp_len;

	i = find_the_divide(len);
	fulcrum = malloc(sizeof(int) * (i * 2));
	tmp_len = len;
	while (len >= 2)
	{
		if (len % 2)
		{
			len = (len / 2);
			tmp_len -= len;
			fulcrum[i++] = lst_sort[0][((*index)->len_a) - tmp_len - 1];
			fulcrum[i++] = len;
		}
		else
		{
			len = len / 2;
			tmp_len -= len;
			fulcrum[i++] = lst_sort[0][((*index)->len_a) - tmp_len - 1];
			fulcrum[i++] = len;
			printf("je suis len == %d\n", len);
		}
	}
	return (fulcrum);
}

int		find_the_tmp_pivot(int **lst_sort, int tmp_len_pivot, int pivot)
{
	int	i;
	int j;

	i = 0;
	while (lst_sort[0][i] != pivot && i < 20)
	{
		printf("lstsort[0][%d] == %d\n", i, lst_sort[0][i]);
		i++;
	}
	j = lst_sort[0][i + tmp_len_pivot];
	exit(EXIT_SUCCESS);
	return(j);
}

void	sort(t_col **index, int pivot, int len_pivot, int stack)
{
	int i;
	t_num *col;

	i = 0;
	while (i < len_pivot)
	{
		if (stack == 2)
			col = (*index)->col_b;
		else
			col = (*index)->col_a;
		if (col->nb >= pivot)
		{
			i++;
			push(index, stack);
		}
		else
			rotate(index, stack);
	}
}

void	un_sort(t_col **index, int pivot, int len_pivot, int stack)
{
	int i;
	t_num *col;

	i = 0;
	while (i < len_pivot)
	{
		if (stack == 2)
			col = (*index)->col_b;
		else
			col = (*index)->col_a;
		if (col->nb < pivot)
		{
			i++;
			push(index, stack);
		}
		else
			rotate(index, stack);
	}
}

int		*change_fulcrum(int *fulcrum, int len, int pivot)
{
	int i;
	int	*nw_fulcrum;

	i = 0;
	while (fulcrum[i] != pivot)
		i++;
	if (i == 0)
	{
		free(fulcrum);
		return (NULL);
	}
	else
	{
		i = i - 1;
		nw_fulcrum = malloc(sizeof(int) * i);
		while (i >= 0)
		{
			nw_fulcrum[i] = fulcrum[i];
			i--;
		}
		free(fulcrum);
	}
	i = -1;
	while (++i < 5)
	{
		printf("nw_fulcrum[%d] == %d\n", i, nw_fulcrum[i]);
	}
	exit(EXIT_SUCCESS);
	return (nw_fulcrum);
}

int		pong_sort(t_col **index, int *len, int *pivot)
{
	int *lst_sort;
	static int *fulcrum;
	int test;//test

	lst_sort = nw_lst_order(&(*index)->col_a, lst_sort, (*index)->len_a, 1);
	if (!lst_sort)
		return (0);
	if (!fulcrum)
	{
		fulcrum = find_the_fulcrum(index, &lst_sort, *len);
		if (!fulcrum)
			return (0);
	}
	(*index)->stack += 2;
	while ((*index)->len_a > (*index)->stack)
	{
		*len = *len / 2;
		*pivot = find_the_tmp_pivot(&lst_sort, *len, *pivot);
		un_sort(index, *pivot, *len, 1);
	}
	printf("pivot == %d\nlen == %d\n", *pivot, *len);
	*pivot = find_the_tmp_pivot(&fulcrum, -2, *pivot);
	*len = find_the_tmp_pivot(&fulcrum, -1 , *pivot);
	change_fulcrum(fulcrum, *len, *pivot);
	free(lst_sort);
	return(1);
}

int		ping_sort(t_col **index, int **lst_sort, int pivot, int len_pivot)
{
	int	tmp_len_pivot;
	int	tmp_pivot;

	tmp_len_pivot = len_pivot / 2;
	tmp_pivot = find_the_tmp_pivot(lst_sort, tmp_len_pivot, pivot);
	while ((*index)->max_b >= pivot)
	{
		while ((*index)->max_b >= tmp_pivot)
			sort(index, tmp_pivot, tmp_len_pivot, 2);
		while ((*index)->last_b >= pivot)
			reverse_rot(index, 2);
		if (tmp_len_pivot > 1)
			pong_sort(index, &tmp_len_pivot, &tmp_pivot);
		else
			(*index)->stack += 1;
	}
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
	i = 3;
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
