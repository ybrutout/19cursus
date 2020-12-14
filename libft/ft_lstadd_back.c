/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:15:22 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/14 10:15:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*nw;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			nw = ft_lstlast(*alst);
			nw->next = new;
			new->next = 0;
		}
	}
}
