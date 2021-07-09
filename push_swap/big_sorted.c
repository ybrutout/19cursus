/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:12:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/09 13:47:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_indx(t_col **index, int **lst_sort)
{
	int		i;
	int		j;
	t_num	*tmp;
	t_num	*col;

	j = 0;
	col = (*index)->col_a;
	while (j < (*index)->len_a)
	{
		i = 0;
		tmp = col->next;
		while (col->nb != lst_sort[0][i])
			i++;
		col->indx = i;
		j++;
		col = tmp;
	}
}

int	str_nbr(int nb)
{
	int	i;

	i = 0;
	while (nb > 1)
	{
		nb = nb / 2;
		i++;
	}
	i += 2;
	return (i);
}

char	*itoa_base_remix(int nb, int size)
{
	char	*c;

	c = malloc(sizeof(char) * size);
	if (!c)
		return (NULL);
	c[--size] = '\0';
	while (nb)
	{
		c[--size] = nb % 2 + 48;
		nb /= 2;
	}
	while (size > -1)
	{
		c[--size] = '0';
	}
	return (c);
}

void	init_binary(t_col **index, int **lst_sort)
{
	t_num	*tmp;
	t_num	*col;
	int		i;
	int		size;

	i = 0;
	col = (*index)->col_a;
	size = str_nbr((*index)->len_a - 1);
	while (i < (*index)->len_a)
	{
		tmp = col->next;
		col->binary = itoa_base_remix(col->indx, size);
		col = tmp;
		i++;
	}
}

int	big_sorted(t_col **index, int **lst_sort)
{
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 1);
	init_indx(index, lst_sort);
	init_binary(index, lst_sort);
	sorted_binary(index);
	exit(EXIT_SUCCESS);
	return (1);
}
