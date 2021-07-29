/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:05:13 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 14:53:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && argv[i][j + 1] >= '0' \
			&& argv[i][j + 1] <= '9')
				j++;
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')))
				return (write(1, "Error\nFalse argument\n", 21));
			else
				j++;
		}
		i++;
	}
	return (1);
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
