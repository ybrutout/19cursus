/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:21:40 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/27 14:55:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_tmp;

	if (!lst || !f)
		return (NULL);
	n_lst = ft_lstnew(f(lst->content));
	if (!n_lst)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		n_tmp = ft_lstnew(f(lst->content));
		if (!n_tmp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&n_tmp, del);
		}
		lst = lst->next;
		ft_lstadd_back(&n_lst, n_tmp);
	}
	return (n_lst);
}
