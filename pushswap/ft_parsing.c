/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:35:21 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/17 15:38:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (lst_sort[0][i] && i < (argc - 1))
	{
		if (lst_sort[0][i] > lst_sort[0][i + 1] && (i + 1) < (argc - 1))
		{
			j = lst_sort[0][i + 1];
			lst_sort[0][i + 1] = lst_sort[0][i];
			lst_sort[0][i] = j;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
}

static int	ft_error(t_num *col_a, int *lst_sort, int b)
{
	ft_free(col_a);
	free(lst_sort);
	if (b == 1)
		return (write(1, "problème de malloc\n", 19));
	if (b == 2)
		return (write(1, "doublons d'arguments\n", 21));
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
			if ((ft_error(*col_a, *lst_sort, 1)) > 0)
				return (1);
		ft_lstadd_back(col_a, lst_tmp);
		lst_sort[0][i - 1] = tmp;
		i++;
	}
	tmp = 0;
	lst_tmp = ft_lstnew(&tmp);
	if (!lst_tmp)
		if ((ft_error(*col_a, *lst_sort, 1)) > 0)
			return (1);
	ft_lstadd_back(col_b, lst_tmp);
	ft_order(lst_sort, i);
	return (0);
}
