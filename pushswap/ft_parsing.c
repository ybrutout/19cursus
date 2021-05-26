/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:35:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/26 13:56:51 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_num *col_a, t_num *col_b, int *lst_sort, int b)
{
	ft_free(col_a);
	if (col_b)
		ft_free(col_b);
	if (lst_sort)
		free(lst_sort);
	if (b == 1)
		return (write(1, "problème de malloc\n", 19));
	if (b == 2)
		return (write(1, "doublons d'arguments\n", 21));
	if (b == 3)
		return (write(1, "error dans median\n", 18));
	return (0);
}

int	parsing(char **argv, t_num **col_a, t_num **col_b, int **lst_sort)
{
	int			tmp;
	int			i;
	t_num		*lst_tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		lst_tmp = ft_lstnew(&tmp);
		if (!lst_tmp)
			if ((ft_error(*col_a, *col_b, *lst_sort, 1)) > 0)
				return (1);
		ft_lstadd_back(col_a, lst_tmp);
		lst_sort[0][i++ - 1] = tmp;
	}
	tmp = 0;
	i = ft_order(lst_sort, i);
	if (i == 0)
		if ((ft_error(*col_a, *col_b, *lst_sort, 2)) > 0)
			return (1);
	return (0);
}
