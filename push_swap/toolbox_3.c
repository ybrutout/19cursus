/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:02:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/19 15:21:54 by ybrutout         ###   ########.fr       */
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
	int		i;

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

int	parsing(char **argv, t_col **index)
{
	int			tmp;
	int			i;
	t_num		*lst_tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i], index);
		lst_tmp = ft_lstnew(&tmp);
		if (!lst_tmp)
		{
			if (i > 1)
				ft_lstclear(&(*index)->col_a);
			return (write(1, "Error\nmalloc index init\n", 24));
		}
		(*index)->col_a = ft_lstadd_back((*index)->col_a, lst_tmp);
		i++;
	}
	change_index(index);
	return (1);
}

int	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	while (i < argc)
	{
		if ((i + 1) < argc && lst_sort[0][i] == lst_sort[0][i + 1])
			return (0);
		else if ((i + 1) < argc && lst_sort[0][i] > lst_sort[0][i + 1])
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
