/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:06:49 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 13:07:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_nb(t_num *col)
{
	t_num	*tmp;
	int		ret;

	tmp = col;
	while (tmp)
	{
		ret = tmp->nb;
		tmp = tmp->next;
	}
	return (ret);
}
