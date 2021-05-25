/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:26:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/25 15:51:34 by ybrutout         ###   ########.fr       */
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
	ft_order(&tmp, (len + 1));
	free(lst_new);
	return (tmp);
}

int	check(t_col **index)
{
	if (ascending(&(*index)->col_a) == 1)
	{
		if (decreasing(&(*index)->col_b) == 1)
		{
			if ((*index)->min_a > (*index)->max_b)
			{
				while((*index)->len_b > 0)
					push(index, 2);
				return (1);
			}
		}
		return (2);
	}
	return (0);
}

int	len_position(t_col **index, int median, char a)
{
	t_num	*tmp;
	int		len;

	len = 0;
	if (a == 'a')
	{
		tmp = (*index)->col_a;
		while (tmp->nb > median)
		{
			tmp = tmp->next;
			len++;
		}
	}
	else if (a == 'b')
	{
		tmp = (*index)->col_a;
		while (tmp->nb > median)
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (len);
}

int	middlepoint(t_col **index, int **lst_sort)
{
	int		len;
	int		median;

	len = (*index)->len_a;
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a);
	if (!*lst_sort)
		return (0);
	median = lst_sort[0][(len/2)];
	while (len > 0)
	{
		if ((*index)->col_a && (*index)->col_a->nb < median)
			push(index, 1);
		else
		{
			if ((*index)->col_b && (*index)->col_b->next && (*index)->col_b->nb < (*index)->col_b->next->nb)
			{
				rotate(index, 3);
			}
			else
				rotate(index, 1);
		}
		len--;
		if (check(index) == 1)
			return (2);
	}
	return (1);
}

int position(t_col **index, int button)
{
	t_num	*tmp;
	int		len;

	len = 0;
	if (button == 1)
	{
		tmp = (*index)->col_b;
		while (tmp->nb != (*index)->max_b)
		{
			tmp = tmp->next;
			len++;
		}
	}
	else if (button == 2)
	{
		tmp = (*index)->col_a;
		while (tmp->nb != (*index)->max_a)
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (len);
}

int	checker(t_col **index)
{
	t_num	*tmp;

	tmp = (*index)->col_a;
	while (tmp)
	{
		if ( tmp->next && tmp->nb > tmp->next->nb)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int	median(t_num **col_a, t_num **col_b, int **lst_sort, int nb)
{
	t_col	*index;
	t_num	*nb_tmp; // pour les tests.
	t_num	*nb_tmp_b;// pour les tests.
	int		i;// pour les tests.
	int		ret;

	i = 0;
	index = int_new_index(col_a, col_b, nb);
	if ((ascending(col_a)) == 1)
	{
		free(index);
		return (1);
	}
	while ((index->len_a) > 2 )
	{
		ret = middlepoint(&index, lst_sort);
		if (ret == 0)
			return (-1);
		else if (ret == 2)
		{
			free(index);
			return (1);
		}
	}
	if (index->len_a == 2)
	{
		if (ascending(&index->col_a) == 0)
		{
			if (decreasing(&index->col_b) == 0)
				swap_button(&index, 3);
			else
				swap_button(&index, 1);
		}
	}
	while (index->len_b != 0)
	{
		if (index->col_b->nb == index->max_b)
			push(&index, 2);
		else if (index->col_b->next->nb == index->max_b)
			swap_button(&index, 2);
		else if (index->col_b->nb == index->min_b)
		{
			push(&index, 2);
			if (position(&index, 1) <= ((index->len_b) / 2))
				rotate(&index, 3);
			else
				rotate(&index, 1);
		}
		else if (index->col_b->nb == nb_second_max(&(index->col_b), index->len_b, index->max_b))
		{
			push(&index, 2);
		}
		else if (position(&index, 1) <= ((index->len_b) / 2))
			rotate(&index, 2);
		else if (position(&index, 1) > ((index->len_b) / 2))
			reverse_rot(&index, 2);
	}
	while (index->col_a->nb != index->min_a)
		reverse_rot(&index, 1);
	//checker
	i = checker(&index);
	if (i == 0)
	{
		write(1, "KO\n", 3);
		printf("%d\n", i);
	}
	else
		write(1, "OK\n", 3);
	//fin checker
	nb_tmp = index->col_a;
	while (nb_tmp)
	{
		printf("%d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
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
