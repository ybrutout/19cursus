/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 12:40:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_write(int button, t_col **index)
{
	static int	i;//test
	t_num	*tmp_a;
	t_num	*tmp_b;

	if (i > 212)
	{
		system("clear");
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
		tmp_a = (*index)->col_a;
		tmp_b = (*index)->col_b;
		printf("		|		\n---------------------------------------------\n");
		while (tmp_a || tmp_b)
		{
			if (!tmp_a)
				printf("		|	%d\n", tmp_b->nb);
			else if (!tmp_b)
				printf("	%d	|		\n", tmp_a->nb);
			else
				printf("	%d	|	%d\n", tmp_a->nb, tmp_b->nb);
			if (tmp_b)
				tmp_b = tmp_b->next;
			if (tmp_a)
				tmp_a = tmp_a->next;
		}
		printf("		|		\n---------------------------------------------\n");
		printf("%d\n", i);
		system("sleep 0.02");
	}
	change_index(index);
	if (!i)
		i = 0;
	i++;
	if (i == 214)
		exit(EXIT_SUCCESS);
}
