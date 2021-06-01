/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:10:31 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 15:42:13 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_num	*nb_tmp;// n'est utile que pour les tests.
	t_num	*nb_tmp_b; // 'est utilisé que pour les tests.
	int		tmp;// n'est utile que pour les tests.
	int		tmp_b; //tests
	int		sign;//tests
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
	free_lst(index->col_a);
	free_lst(index->col_b);
	free(lst_sort);
	free(index);
	//system("leaks push_swap");
}
