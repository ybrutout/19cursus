/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:12:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/08 16:22:29 by ybrutout         ###   ########.fr       */
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
	col = (*index)->col_a;
	j = 0;
	while (j < (*index)->len_a)
	{
		tmp = col->next;
		printf("nb = %d - index = %d\n", col->nb, col->indx);
		col = tmp;
		j++;
	}
}

int		str_nbr(int nb)
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
		return(NULL);
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
	return(c);
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
	i = 0;
	col = (*index)->col_a;
	while(i < (*index)->len_a)
	{
		tmp = col->next;
		printf("%d	==	%d	=>	%d	=>	%s\n", i, col->nb, col->indx, col->binary);
		col = tmp;
		i++;
	}
}

int		there_is_a_zero(t_num *col, int nb)
{
	while (col)
	{
		if (col->binary[nb] == '0')
			return(0);
		col = col->next;
	}
	return (1);
}

void	sorted_binary(t_col **index)
{
	int	i;

	i = (str_nbr((*index)->len_a));
	while (ascending((*index)->col_a, (*index)->len_a) != 1 && (*index)->len_b != 0)
	{
		while (there_is_a_zero((*index)->col_a))
	}
}

int 	big_sorted(t_col **index, int **lst_sort)
{
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 1);
	init_indx(index, lst_sort);
	init_binary(index, lst_sort);
	exit(EXIT_SUCCESS);
	return (1);
}
