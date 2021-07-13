/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:16:24 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 14:36:44 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_2(char *new_str, unsigned long long *number, int sign)
{
	unsigned long long		nmb_tmp;

	while (*new_str >= '0' && *new_str <= '9')
	{
		nmb_tmp = *number;
		*number = 10 * (*number) + (*new_str - '0');
		if ((*number) < nmb_tmp || (*number) > LLONG_MAX)
			return (-1);
		new_str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long		number;
	int						sign;
	char					*new_str;

	sign = 1;
	number = 0;
	new_str = (char *)str;
	if (*new_str == '-' && new_str++)
		sign *= -1;
	else if (*new_str == '+')
		new_str++;
	if ((ft_atoi_2(new_str, &number, sign)) < 0)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (number * sign);
}

t_col	*ft_lstnew(int *content)
{
	t_col	*new;

	new = malloc(sizeof(t_col));
	if (!new)
		return (NULL);
	new->nb = *content;
	new->next = 0;
	return (new);
}

t_col	*ft_lstadd_back(t_col *alst, t_col *new)
{
	t_col	*nw;

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

int	ft_lstsize(t_col *lst)
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
