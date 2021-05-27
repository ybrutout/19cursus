/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:14 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 14:22:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_error(t_col *index, int *lst_sort, int b)
{
	write(1, "Error\n", 6);
	if (b == 0)
		write(1, "index malloc\n", 13);
	else if (b == 1)
		write(1, "not enough argument\n", 20);
	else if (b == 2)
		write(1, "initiation of the sorted list\n", 30);
	else if (b == 3)
		write(1, "parsing lst\n", 20);
	if (b > 1)
		free(index);
	if (b > 2)
		free(lst_sort);
	if (b > 3)
	{
		free_lst(index->col_a);
	}
	if (b > 4)
	{
		if (index->col_b)
			free_lst(index->col_b);
	}
	return (0);
}

void	free_lst(t_num *alst)
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

/*if (b == 1)
		return (write(1, "problème de malloc\n", 19));
	if (b == 2)
		return (write(1, "doublons d'arguments\n", 21));
	if (b == 3)
		return (write(1, "error dans median\n", 18));*/
