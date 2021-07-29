/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:53:25 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 14:59:39 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp_check(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

char	*ft_strcat(char *str, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(*new) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	if (str)
		while (str[++i])
			new[i] = str[i];
	if (i == -1)
		i = 0;
	j = -1;
	if (buffer)
		while (buffer[++j])
			new[i + j] = buffer[j];
	new[i + j] = '\0';
	free(str);
	return (new);
}

int	ft_compare(t_col **index, char *line)
{
	if (ft_strcmp_check(line, "sa\n") == 1)
		ft_operation(index, 1);
	else if (ft_strcmp_check(line, "sb\n") == 1)
		ft_operation(index, 2);
	else if (ft_strcmp_check(line, "ss\n") == 1)
		ft_operation(index, 3);
	else if (ft_strcmp_check(line, "pb\n") == 1)
		ft_operation(index, 5);
	else if (ft_strcmp_check(line, "pa\n") == 1)
		ft_operation(index, 4);
	else if (ft_strcmp_check(line, "ra\n") == 1)
		ft_operation(index, 6);
	else if (ft_strcmp_check(line, "rb\n") == 1)
		ft_operation(index, 7);
	else if (ft_strcmp_check(line, "rr\n") == 1)
		ft_operation(index, 8);
	else if (ft_strcmp_check(line, "rra\n") == 1)
		ft_operation(index, 9);
	else if (ft_strcmp_check(line, "rrb\n") == 1)
		ft_operation(index, 10);
	else if (ft_strcmp_check(line, "rrr\n") == 1)
		ft_operation(index, 11);
	else
		return (0);
	return (1);
}
