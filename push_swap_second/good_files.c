/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:52:35 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 14:42:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_index(t_ind **index)
{
	int	tmp;
	tmp = ft_lstsize((*index)->col_a);
	(*index)->len_a = tmp;
	tmp = ft_lstsize((*index)->col_b);
	(*index)->len_b = tmp;
	if ((*index)->len_a > 0)
	{
		tmp = nb_max(&((*index)->col_a), (*index)->len_a);
		(*index)->max_a = tmp;
		tmp = nb_min(&((*index)->col_a), (*index)->len_a);
		(*index)->min_a = tmp;
	}
	if ((*index)->len_b > 0)
	{
		tmp = nb_max(&((*index)->col_b), (*index)->len_b);
		(*index)->max_b = tmp;
		tmp = nb_min(&((*index)->col_b), (*index)->len_b);
		(*index)->min_b = tmp;
	}
	tmp = last_nb((*index)->col_a, (*index)->len_a);
	(*index)->last_a = tmp;
	tmp = last_nb((*index)->col_b, (*index)->len_b);
	(*index)->last_b = tmp;
}

int	

int	parsing(char **argv, t_ind **index, int **lst)
{
	int			tmp;
	int			i;
	t_col		*lst_tmp;

	i = 1;
	while (argv[i])
	{
		if (argv[i] > INT_MAX || argv[i] < INT_MIN || )
			return(index, lst, 0, 2);
		tmp = ft_atoi(argv[i]);
		lst_tmp = ft_lstnew(&tmp);
		if (!lst_tmp)
			return (ft_error(index, lst, 0, 3));
		(*index)->col_a = ft_lstadd_back((*index)->col_a, lst_tmp);
		i++;
	}
	change_index(index);
	return (1);
}

int	is_a_good_files(char **argv, t_ind **index, int **lst_sort)
{
	int i;

	if ((*index)->argc < 2)
		return(ft_error(index, lst_sort, 0, 1));
	i = 0;
	if (parsing(argv, index, lst_sort) == 0)
		return (0);

}
