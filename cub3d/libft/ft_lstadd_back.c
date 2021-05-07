/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:15:22 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:56:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include	<stdio.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*nw;

	if (!alst)
		return ;
	printf("%p\n", *alst);
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	nw = *alst;
	while (nw->next)
	{
		nw = nw->next;
	}
	nw->next = new;
}
