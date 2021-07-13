/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:54:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 14:35:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ret_nb(t_ind **index, int **lst, int button)
{
	if (button == 0)
		write(1, "init lst\n", 9);
	else if (button == 1)
		write(1, "not enough argument\n", 20);
	else if (button == 2)
		write(1, "wrong argument\n", 15);
	else if (button == 3)
		write(1, "error malloc\n", 13);
	if (button > 0)
		ft_free(index, lst);
	return (0);
}

void	*ret_null(t_ind **index, int **lst, int button)
{
	if (button == 0)
		write(1, "init index\n", 11);
	else if (button == 1)
		write(1, "malloc error\n", 13);
	if (button > 0)
		free(index);
	return (NULL);
}

void	ft_lst_clear(t_col *col)
{
	t_col	*tmp;

	while (col)
	{
		tmp = col->next;
		free(col);
		col = tmp;
	}
}

int	ft_free(t_ind **index, int **lst_sort)
{
	if ((*index)->col_a != NULL)
		ft_lst_clear((*index)->col_a);
	if ((*index)->col_b != NULL)
		ft_lst_clear((*index)->col_b);
	free(lst_sort);
	free(index);
}

int	ft_error(t_ind **index, int **lst, int nb, int button)
{
	if (nb == 0)
		return (ret_nb(index, lst, button));
	else if (nb == 1)
		return(ret_null(index, lst, button));
	free(index);
}
