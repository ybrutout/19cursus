/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:12:22 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/04 18:28:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*gnl_strdup(const char *save, char c)
{
	char	*new_s1;
	int		i;

	i = ft_strlen(save) + 1;
	new_s1 = (char *)malloc(sizeof(char) * i);
	if (!(new_s1))
		return (0);
	i = 0;
	while (save[i] != c)
	{
		new_s1[i] = save[i];
		i++;
	}
	new_s1[i] = 0;
	return (new_s1);
}

void		gnl_sve(char *save)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i])
		i++;
	while (save[++i])
	{
		save[j] = save[i];
		j++;
	}
	save[j] = 0;
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	size;
	size_t	j;

	if (s1)
		size = ft_strlen(s1) + ft_strlen(s2);
	else
		size = ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (size + 1));
	if (!(new_s))
		return (0);
	i = 0;
	j = -1;
	if (s1)
		while (i < ft_strlen(s1))
			new_s[i++] = s1[++j];
	j = -1;
	while (i < size)
		new_s[i++] = s2[++j];
	new_s[i] = 0;
	return (new_s);
}

size_t		ft_strlen(const char *s)
{
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}
