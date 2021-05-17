/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:06:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/17 15:30:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_num *alst)
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
