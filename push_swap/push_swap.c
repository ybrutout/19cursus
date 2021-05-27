/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:10:31 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/27 14:30:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_num	*nb_tmp;// n'est utile que pour les tests.
	t_num	*nb_tmp_b; // 'est utilisé que pour les tests.
	t_num	*col_a;
	t_num	*col_b;
	int		tmp;// n'est utile que pour les tests.
	int		tmp_b; //tests
	int		*lst_sort;
	t_col	*index;

	if (argc < 3)
		return (ft_error(index, lst_sort, 1));
	index = int_new_index(&col_a, &col_b, (argc - 1));
	if (!index)
		return(ft_error(index, lst_sort, 0));
	if (parsing(argv, &index, &lst_sort) == 0)
		return (0);
	if (sorted(&index, &lst_sort) == 0)
		return (0);
	free_lst(index->col_a);
	free_lst(index->col_b);
	free(lst_sort);
	free(index);
	system("leaks push_swap");
	/*
	if ((median(&index, &lst_sort, (argc - 1))) < 0)
		if ((ft_error(col_a, col_b, lst_sort, 3)) > 0)
			return (0);
	ft_free(col_a);
	ft_free(col_b);
	free(index);
	free(lst_sort);*/
}

/*nb_tmp = index->col_a;
	while (nb_tmp)
	{
		printf("nb == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}*/

/*	nb_tmp = index->col_a;
	nb_tmp_b = index->col_b;
	printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while (nb_tmp || nb_tmp_b)
	{
		tmp = '\0';
		tmp_b = '\0';
		if (nb_tmp)
		{
			tmp = nb_tmp->nb;
			nb_tmp = nb_tmp->next;
		}
		if (nb_tmp_b)
		{
			tmp_b = nb_tmp_b->nb;
			nb_tmp_b = nb_tmp_b->next;
		}
		if (tmp != '\0' && tmp_b != '\0')
			printf("		%d		|		%d		\n", tmp, tmp_b);
		else if (tmp == '\0' && tmp_b != 0)
			printf("		%c		|		%d 		\n", ' ', tmp_b);
		else if (tmp_b == '\0')
			printf("		%d		|		%c		\n", tmp, ' ');
	}
	printf("--------------------------------|--------------------------------\n");*/
