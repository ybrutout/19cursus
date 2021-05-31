/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:21:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/31 11:54:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*nw_lst_order(t_num **col, int *lst_new, int len, int knob)
{
	int		*tmp;
	t_num	*tmp_col;
	int 	i;

	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		return (NULL);
	i = 0;
	if (*col)
	{
		tmp_col = *col;
		while (tmp_col)
		{
			tmp[i++] = tmp_col->nb;
			tmp_col = tmp_col->next;
		}
	}
	tmp[len] = 0;
	ft_order(&tmp, len);
	if (knob != 1)
		free(lst_new);
	return (tmp);
}

int	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	while (i < argc)
	{
		if (lst_sort[0][i] == lst_sort[0][i + 1] && (i + 1) < argc)
			return (0);
		else if (lst_sort[0][i] > lst_sort[0][i + 1] && (i + 1) < argc)
		{
			j = lst_sort[0][i + 1];
			lst_sort[0][i + 1] = lst_sort[0][i];
			lst_sort[0][i] = j;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

t_col	*int_new_index(t_num **col_a, t_num **col_b, int nb)
{
	t_col *index;

	index = malloc(sizeof(t_col));
	if (!index)
		return (NULL);
	index->col_a = *col_a;
	index->col_b = *col_b;
	index->max = 0;
	index->max_a = 0;
	index->min = 0;
	index->min_a = 0;
	index->min_b = 0;
	index->max_b = 0;
	index->argc = nb;
	index->len_a = 0;
	index->len_b = 0;
	index->last_a = 0;
	index->last_b = 0;
	return(index);
}

void	change_index(t_col **index)
{
	int	tmp;
	tmp = ft_lstsize((*index)->col_a);
	(*index)->len_a = tmp;
	tmp = ft_lstsize((*index)->col_b);
	(*index)->len_b = tmp;
	if ((*index)->len_a > 0)
	{
		tmp = nb_max(&((*index)->col_a), (*index)->len_a);
		(*index)->max_a = tmp;
		tmp = nb_min(&((*index)->col_a), (*index)->len_a);
		(*index)->min_a = tmp;
	}
	if ((*index)->len_b > 0)
	{
		tmp = nb_max(&((*index)->col_b), (*index)->len_b);
		(*index)->max_b = tmp;
		tmp = nb_min(&((*index)->col_b), (*index)->len_b);
		(*index)->min_b = tmp;
	}
	tmp = last_nb((*index)->col_a);
	(*index)->last_a = tmp;
	tmp = last_nb((*index)->col_b);
	(*index)->last_b = tmp;
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
	system("clear");
	if (button > 0 && button < 12)
	{
		//printf("n %d ", nb_tests++);
		//printf("command == ");
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
	printf("nb commande : %d\n", nb_comm);
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
	//problème avec zero qu'il faut régler
}
