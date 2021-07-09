/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:47:54 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/09 12:49:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_binary(t_col **index)
{
	int		i;
	int		f;

	i = (str_nbr((*index)->len_a) - 2);
	f = 0;
	while (i > -1)
	{
		f = 0;
		while (f < (*index)->argc)
		{
			if (this_is_a_zero((*index)->col_a->binary, i) == 0)
				push(index, 1);
			else
				rotate(index, 1);
			f++;
		}
		while ((*index)->len_b != 0)
			push(index, 2);
		i--;
	}
}

int	there_is_a_zero(t_num *col, int nb, char c)
{
	while (col)
	{
		if (col->binary[nb] == c)
			return (0);
		col = col->next;
	}
	return (1);
}

int	this_is_a_zero(char *binary, int nb)
{
	if (binary[nb] == '0')
		return (0);
	return (1);
}
