/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:07:09 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/19 11:09:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_num	*nb_tmp;// n'est utile que pour les tests.
	t_num	*nb_tmp_b; // 'est utilisé que pour les tests.
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
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	while (nb_tmp_b && nb_tmp_b->next)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp->next;
	}
	if (!(nb_tmp_b->next))
		printf("\nhey b n'existe pas\n\n");
	tmp = 0;
	while (lst_sort[tmp] && tmp < (argc - 1))
	{
		printf("sorted == %d\n", lst_sort[tmp]);
		tmp++;
	}
	//jusque ici et c'est 20 lignes.
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


 // test pour voir si le push fonctionne
 /*	printf("\nhey je suis au push\n\n");
	printf("ici c'est push a sur b\n");
	push(&col_b, &col_a, 1);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst 1 == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("ici c'est push b sur a\n");
	push(&col_a, &col_b, 1);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst 1 == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("\n\nhey c'est la fin du push \n");*/

	//test pour voir si le rotate fonctionne.
	/*printf("\nhey je suis au rotate\n\n");
	printf("ici c'est rotate a\n");
	rotate(&col_a, &col_b, 1);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("\n");
	printf("ici c'est rotate b\n");
	rotate(&col_b, &col_a, 2);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("ici c'est rotate a et b\n");
	rotate(&col_b, &col_a, 3);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("\n\nhey c'est la fin du push \n");*/

	//reverse rotate tests.
	/*	printf("\nhey je suis au reverse rotate\n\n");
	printf("ici c'est reverse rotate a\n");
	reverse_rot(&col_a, &col_b, 1);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("\n");
	printf("ici c'est reverse rotate b\n");
	reverse_rot(&col_b, &col_a, 2);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("ici c'est reverse rotate a et b\n");
	reverse_rot(&col_b, &col_a, 3);
	nb_tmp = col_a;
	nb_tmp_b = col_b;
	while (nb_tmp)
	{
		printf("lst_a == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}
	printf("\n");
	while (nb_tmp_b)
	{
		printf("lst_b == %d\n", nb_tmp_b->nb);
		nb_tmp_b = nb_tmp_b->next;
	}
	printf("\n\nhey c'est la fin du reverse rotate \n");*/


