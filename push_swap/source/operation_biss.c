/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_biss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:20:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:57:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_bis(t_col **index, int nb)
{
	t_num	*tmp;

	if (nb == 1)
	{
		tmp = (*index)->col_a;
		(*index)->col_a = (*index)->col_a->next;
		tmp->next = NULL;
		(*index)->col_a = ft_lstadd_back((*index)->col_a, tmp);
	}
	else
	{
		tmp = (*index)->col_b;
		(*index)->col_b = (*index)->col_b->next;
		tmp->next = NULL;
		(*index)->col_b = ft_lstadd_back((*index)->col_b, tmp);
	}
}

void	reverse_rott_biss(t_col **index, int len, int nb)
{
	t_num	*start;
	t_num	*tmp;

	if (nb == 1)
	{
		len = ft_lstsize((*index)->col_a);
		start = (*index)->col_a;
		while (len-- != 2)
			start = start->next;
		tmp = start->next;
		start->next = NULL;
		tmp->next = (*index)->col_a;
		(*index)->col_a = tmp;
	}
	else
	{
		len = ft_lstsize((*index)->col_b);
		start = (*index)->col_b;
		while (len-- != 2)
			start = start->next;
		tmp = start->next;
		start->next = NULL;
		tmp->next = (*index)->col_b;
		(*index)->col_b = tmp;
	}
}
