/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:21:40 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/12 16:52:31 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_tmp;

	if (!lst || !f)
		return (NULL);
	if (!(n_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(n_tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&n_lst, n_tmp);
	}
	return (n_lst);
}
