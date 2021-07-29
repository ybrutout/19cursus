/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:53:25 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:55:06 by ybrutout         ###   ########.fr       */
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
		return(0);
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
