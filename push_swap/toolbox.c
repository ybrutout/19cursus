/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/03 16:22:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	tmp = last_nb((*index)->col_a, (*index)->len_a);
	(*index)->last_a = tmp;
	tmp = last_nb((*index)->col_b, (*index)->len_b);
	(*index)->last_b = tmp;
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

void	free_lst(t_num *alst)
{
	t_num	*tmp;
	t_num	*tmp_tmp;

	if (!alst)
		return ;
	tmp = alst;
	while (tmp->next)
	{
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
	free(tmp);
}

void	check(t_col	**index, int comm)
{
	int len;
	t_num	*col_a;
	t_num	*col_b;
	int		nb_a;
	int		nb_b;
	int		c;
	//system("clear");

	len = (*index)->argc;
	col_a = (*index)->col_a;
	col_b = (*index)->col_b;
	c = 0;
	printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while (len != 0)
	{
		if (col_a)
		{
			len--;
			nb_a = col_a->nb;
			col_a = col_a->next;
		}
		else
			c = 1;
		if (col_b)
		{
			len--;
			nb_b = col_b->nb;
			col_b = col_b->next;
		}
		else
			c = 2;
		if (c == 0)
			printf("		%d		|		%d		\n", nb_a, nb_b);
		else if (c == 1)
			printf("		%c		|		%d		\n", ' ', nb_b);
		else if (c == 2)
			printf("		%d		|		%c		\n", nb_a, ' ');
		c = 0;
	}
	/*if (comm > 201 && comm < 250)
		system("sleep 2");
	else*/
	//	system("sleep 0.01");
}

void	ft_write(int button, t_col **index)
{
	static int	nb_comm;

	if (!nb_comm)
		nb_comm = 0;
	if (button > 0 && button < 12)
	{
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
	}
	nb_comm++;
	change_index(index);
	//check(index, nb_comm);
	//if (nb_comm > 201 && nb_comm < 250)
	//{
	//	if (nb_comm == 215)
	//		exit(EXIT_SUCCESS);
	//	printf("%d\n", nb_comm);
	//}
}
