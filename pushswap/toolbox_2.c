/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:11:46 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/26 16:28:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_index(t_col **index)
{
	(*index)->len_a = ft_lstsize((*index)->col_a);
	(*index)->len_b = ft_lstsize((*index)->col_b);
	if ((*index)->len_a > 0)
	{
		(*index)->max_a = nb_max(&(*index)->col_a, (*index)->len_a);
		(*index)->min_a = nb_min(&(*index)->col_a, (*index)->len_a);
	}
	if ((*index)->len_b > 0)
	{
		(*index)->max_b = nb_max(&(*index)->col_b, (*index)->len_b);
		(*index)->min_b = nb_min(&(*index)->col_b, (*index)->len_b);
	}
	(*index)->last_a = last_nb((*index)->col_a);
	(*index)->last_b = last_nb((*index)->col_b);
}

void	ft_write(int button, t_col **index)
{
	static int	nb_comm;
	static int	nb_tests; //tests
	t_num 		*tmp; // tests
	t_num 		*tmp_b;// tests
	int			nb_a; // tests
	int			nb_b;// tests

	if (!nb_comm)
	{
		nb_tests = 1;
		nb_comm = 0;
	}
	//system("clear");
	if (button > 0 && button < 12)
	{
		printf("n %d ", nb_tests++);
		printf("command == ");
		if (button == 1)
			printf("sa\n");
		else if (button == 2)
			printf("sb\n");
		else if (button == 3)
			printf("ss\n");
		else if (button == 4)
			printf("pa\n");
		else if (button == 5)
			printf("pb\n");
		else if (button == 6)
			printf("ra\n");
		else if (button == 7)
			printf("rb\n");
		else if (button == 8)
			printf("rr\n");
		else if (button == 9)
			printf("rra\n");
		else if (button == 10)
			printf("rrb\n");
		else if (button == 11)
			printf("rrr\n");
		nb_comm++;
	}
	change_index(index);
	//les tests commencent ici.
	/*printf("nb commande : %d\n", nb_comm);
	tmp = (*index)->col_a;
	tmp_b = (*index)->col_b;
	printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while (tmp || tmp_b)
	{
		nb_a = '\0';
		nb_b = '\0';
		if (tmp)
		{
			nb_a = tmp->nb;
			tmp = tmp->next;
		}
		if (tmp_b)
		{
			nb_b = tmp_b->nb;
			tmp_b = tmp_b->next;
		}
		if (nb_a != '\0' && nb_b != '\0')
			printf("		%d		|		%d		\n", nb_a, nb_b);
		else if (nb_a == '\0' && nb_b != 0)
			printf("		%c		|		%d 		\n", ' ', nb_b);
		else if (nb_b == '\0')
			printf("		%d		|		%c		\n", nb_a, ' ');
	}
	printf("--------------------------------|--------------------------------\n");
	// Et ils finissent ici !
	system("sleep 0.01");
	//problème avec zero qu'il faut régler*/
}
