/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:50:46 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/19 10:32:45 by ybrutout         ###   ########.fr       */
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
	while ((*new_str >= 9 && *new_str <= 13) || *new_str == ' ')
		new_str++;
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

void	ft_lstadd_back(t_num **alst, t_num *new)
{
	t_num	*nw;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	nw = *alst;
	while (nw->next)
		nw = nw->next;
	nw->next = new;
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
