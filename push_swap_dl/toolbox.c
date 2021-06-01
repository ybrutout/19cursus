/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:21:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 10:22:55 by ybrutout         ###   ########.fr       */
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

t_col	*int_new_index(int nb)
{
	t_col *index;

	index = malloc(sizeof(t_col));
	if (!index)
		return (NULL);
	index->col_a = NULL;
	index->col_b = NULL;
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

	if (!nb_comm)
	{
		nb_tests = 1;
		nb_comm = 0;
	}
	//system("clear");
	if (button > 0 && button < 12)
	{
	//	printf("n %d ", nb_tests++);
	//	printf("command == ");
		if (button == 1)
			write(1, "sa\n", 3);
		else if (button == 2)
			write(1, "sb\n", 3);
		else if (button == 3)
			write(1, "ss\n", 3);
		else if (button == 4)
			write(1, "pa\n", 3);
		else if (button == 5)
			write(1, "pb\n", 3);
		else if (button == 6)
			write(1, "ra\n", 3);
		else if (button == 7)
			write(1, "rb\n", 3);
		else if (button == 8)
			write(1, "rr\n", 3);
		else if (button == 9)
			write(1, "rra\n", 4);
		else if (button == 10)
			write(1, "rrb\n", 4);
		else if (button == 11)
			write(1, "rrr\n", 4);
		nb_comm++;
	}
	change_index(index);
	nb_tests++;
	//printf("nb_tests == %d\n", nb_tests);
	/*if (nb_tests == 300)
	{
		//les tests commencent ici.
		t_num	*tmp;//tests
		t_num	*tmp_b;//tests
		int		nb_a;//tests
		int		nb_b;//tests
		int		len;
		char	a;
		char	b;

		tmp_b = (*index)->col_b;
		tmp = (*index)->col_a;
		len = (*index)->argc;
		printf("		A		|		B		\n");
		printf("--------------------------------|--------------------------------\n");
		while (len != 0)
		{
			//printf("tmp->nb == %d\n", tmp->nb);
			if (tmp)
			{
				len --;
				nb_a = tmp->nb;
				tmp = tmp->next;
			}
			else
				a = ' ';
			if (tmp_b)
			{
				len--;
				nb_b = tmp_b->nb;
				tmp_b = tmp_b->next;
			}
			else
				b = ' ';
			if (b == ' ')
				printf("		%d		|		%c		\n", nb_a, b);
			else if (a == ' ')
				printf("		%c		|		%d		\n", a, nb_b);
			else
			{
				//printf("nb_a == %d, nb_b == %d \n", nb_a, nb_b);
				printf("		%d		|		%d		\n", nb_a, nb_b);
			}
			a = 'd';
			b = 'd';
		}
		printf("--------------------------------|--------------------------------\n");
		exit(EXIT_SUCCESS);
		// Et ils finissent ici !
		//system("sleep 0.01");
		//problème avec zero qu'il faut régler
	}*/
}
