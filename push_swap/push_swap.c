/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:10:31 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/15 15:28:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_sorted(t_col **index)
{
	t_num	*tmp;
	int		tmp_nb;
	if ((*index)->len_b != 0)
		return (0);
	tmp_nb = (*index)->col_a->nb;
	tmp = (*index)->col_a;
	while ((*index)->argc > 1)
	{
		tmp = tmp->next;
		if (tmp_nb > tmp->nb)
		{
			printf("%d\n%d\n", tmp_nb, tmp->nb);
			return(0);
		}
		else
			tmp_nb = tmp->nb;
		(*index)->argc = ((*index)->argc) - 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*lst_sort;
	t_col	*index;

	if (argc < 3)
		return (0);
	index = int_new_index((argc - 1));
	if (!index)
		return(0);
	if (parsing(argv, &index) == 0)
		return (0);
	if (sorted(&index, &lst_sort) == 0)
		return (0);
	if (chek_sorted(&index) == 0)
		return(write(1, "je suis pas dans l'ordre\n", 25));
	free_lst(index->col_a);
	free_lst(index->col_b);
	free(lst_sort);
	free(index);
	system("leaks push_swap");
}
