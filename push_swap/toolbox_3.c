/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:02:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 15:17:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_nb(t_num *col, int	len)
{
	t_num	*tmp;
	int		ret;

	tmp = col;
	while (len != 0)
	{
		ret = tmp->nb;
		tmp = tmp->next;
		len--;
	}
	return (ret);
}

int	*nw_lst_order(t_num **col, int *lst_new, int len, int knob)
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
		while (i < len)
		{
			tmp[i++] = tmp_col->nb;
			tmp_col = tmp_col->next;
		}
	}
	ft_order(&tmp, len);
	if (knob != 1)
		free(lst_new);
	return (tmp);
}

int	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	while (i < argc)
	{
		if (lst_sort[0][i] == lst_sort[0][i + 1] && (i + 1) < argc)
			return (0);
		else if (lst_sort[0][i] > lst_sort[0][i + 1] && (i + 1) < argc)
		{
			j = lst_sort[0][i + 1];
			lst_sort[0][i + 1] = lst_sort[0][i];
			lst_sort[0][i] = j;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}
