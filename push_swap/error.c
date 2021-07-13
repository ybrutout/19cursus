/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:29:46 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 11:45:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*error_malloc(int nb)
{
	write(1, "Error\n", 6);
	write(1, "Malloc failed ", 13);
	if (nb == 0)
		write(1, "int_new_index\n", 14);
	if (nb == 1)
		write(1, "lst_new\n", 8);
	return (NULL);
}
