/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 14:41:52 by ybrutout         ###   ########.fr       */
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
	change_index(index);
}
