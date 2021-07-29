/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:16:24 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:57:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str, t_col **index)
{
	long	num;
	int		neg;
	int		length;

	neg = 1;
	num = 0;
	length = -1;
	if (*str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && ++length > -1)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if ((num * neg) > (long)(2147483647) || (num * neg)
		< (long)(-2147483648) || length > 9)
		ft_error_message(index, 0);
	return ((int)(num * neg));
}

t_num	*ft_lstnew(int *content)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->nb = *content;
	new->next = 0;
	return (new);
}

t_num	*ft_lstadd_back(t_num *alst, t_num *new)
{
	t_num	*nw;

	if (!alst)
	{
		alst = new;
		return (alst);
	}
	nw = alst;
	while (nw->next)
		nw = nw->next;
	nw->next = new;
	return (alst);
}

void	ft_lstclear(t_num **lst)
{
	t_num			*new;

	if (lst && *lst)
	{
		while (*lst)
		{
			new = (*lst)->next;
			free(*lst);
			*lst = new;
		}
	}
}

int	ft_lstsize(t_num *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
