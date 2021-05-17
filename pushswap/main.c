/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:07:09 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/17 15:57:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_num	*nb_tmp;// n'est utile que pour les tests.
	t_num	*col_a;
	t_num	*col_b;
	int			tmp;// n'est utile que pour les tests.
	int			*lst_sort;

	if (argc < 2)
		return (write(1, "hey, j'ai pas assez d'argument !\n", 33));
	lst_sort = malloc(sizeof(int) * (argc - 1));
	if (!lst_sort)
		return (write(1, "probleme de malloc avec lst_sort\n", 35));
	if (parsing(argv, &col_a, &col_b, &lst_sort) == 1)
		return (0);
	
	//ici ca sers a rien juste pour les tests
	nb_tmp = col_a;
	while (nb_tmp)
	{
		printf("lst == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	tmp = 0;
	while (lst_sort[tmp] && tmp < (argc - 1))
	{
		printf("sorted == %d\n", lst_sort[tmp]);
		tmp++;
	}
	//jusque ici et c'est 12 lignes.
	ft_free(col_a);
	ft_free(col_b);
	system("leaks push_swap");
}

//test pour voir si le swap fonctionne
/*	swap_button(&col_a, &col_b, 1);
	nb_tmp = col_a;
	while (nb_tmp)
	{
		printf("lst 1 == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	swap_button(&col_b, &col_a, 2);
	nb_tmp = col_a;
	while (nb_tmp)
	{
		printf("lst 2 == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	swap_button(&col_a, &col_b, 3);
	nb_tmp = col_a;
	while (nb_tmp)
	{
		printf("lst 3 == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}*/
