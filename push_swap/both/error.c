/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:29:46 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 08:49:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_message(t_col **index, int nb)
{
	write(1, "Error\n", 6);
	if (nb > 0)
	{
		if ((*index)->col_a)
			ft_lstclear(&(*index)->col_a);
		if ((*index)->col_b)
			ft_lstclear(&(*index)->col_b);
		free(index);
	}
	if (nb == -1)
		write(1, "Malloc error\n", 13);
	if (nb == 0)
		write(1, "False argument\n", 15);
	exit(EXIT_FAILURE);
}
