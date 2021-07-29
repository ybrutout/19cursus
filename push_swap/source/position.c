/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:24:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 15:24:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	position_for(t_num *col, int nb)
{
	t_num	*tmp_col;
	int		len;

	tmp_col = col;
	len = 0;
	while (tmp_col)
	{
		if (tmp_col->nb == nb)
			break ;
		tmp_col = tmp_col->next;
		len++;
	}
	return (len);
}

static int	position_biss(t_num *col, int sign, int len_max, int len)
{
	int	i;
	int	sign_tmp;
	int	len_tmp;
	int	nb;

	i = -1;
	nb = nb_max(&col, len);
	len_tmp = position_for(col, nb_min(&col, len));
	while (++i != 2)
	{
		sign_tmp = 1;
		if (len_tmp > (len / 2))
		{
			len_tmp = len - len_tmp;
			sign_tmp = -1;
		}
		if (len_max > len_tmp)
		{
			len_max = len_tmp;
			sign = sign_tmp;
		}
		len_tmp = position_for(col, nb_second_max(&col, len, nb));
		i++;
	}
	return (len_max * sign);
}

int	position(t_col **index, t_num *col, int len, int middle)
{
	int	len_max;
	int	sign;

	len_max = position_for(col, nb_max(&col, len));
	sign = 1;
	if (len_max > middle)
	{
		len_max = len - len_max;
		sign = -1;
	}
	len_max = position_biss(col, sign, len_max, len);
	return (len_max);
}
