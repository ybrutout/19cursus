/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:17:20 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 11:30:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char **argv, t_col **index)
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
			return (ft_error(*index, NULL, 3));
		(*index)->col_a = ft_lstadd_back((*index)->col_a, lst_tmp);
	}
	change_index(index);
	return (1);
}

/*lst_tmp = (*index)->col_a;
	while (lst_tmp)
	{
		printf("col_a == %d\n", lst_tmp->nb);
		lst_tmp = lst_tmp->next;
	}*/


