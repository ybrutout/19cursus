/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:01:37 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/06 13:16:14 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*nw;
	
	if(alst && new)
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