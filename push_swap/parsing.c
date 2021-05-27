/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:17:20 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 14:15:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char **argv, t_col **index, int **lst_sort)
{
	int			tmp;
	int			i;
	t_num		*lst_tmp;

	i = 1;
	*lst_sort = malloc(sizeof(int) * ((*index)->argc));
	if (!lst_sort)
		return(ft_error(*index, *lst_sort, 2));
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		lst_tmp = ft_lstnew(&tmp);
		if (!lst_tmp)
			return (ft_error(*index, *lst_sort, 3));
		ft_lstadd_back(&(*index)->col_a, lst_tmp);
		lst_sort[0][i++ - 1] = tmp;
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


