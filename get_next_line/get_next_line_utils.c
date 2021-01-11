/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:12:22 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/11 18:08:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*gnl_strdup(char *save, char c)
{
	char	*new_s1;
	int		i;

	i = 0;
	while (save[i] != c && save[i])
		i++;
	if (!(new_s1 = (char *)malloc(sizeof(char) * i + 1)))
	{
		free((void *)save);
		return (NULL);
	}
	i = 0;
	while (save[i] != c && save[i])
	{
		new_s1[i] = save[i];
		i++;
	}
	new_s1[i] = 0;
	return (new_s1);
}

int			gnl_if_free(char *s1, int j, char *s2)
{
	s1[j] = 0;
	free(s2);
	if (!s1[0])
	{
		free((void *)s1);
		return (0);
	}
	return (1);
}

char		*gnl_sve(char *save, char c)
{
	int		i;
	int		j;
	char	*new_s1;
	int		size;

	i = 0;
	j = 0;
	while (save[i] != c && save[i])
		i++;
	size = ft_strlen(&save[i]);
	if (!(new_s1 = (char *)malloc(sizeof(char) * size + 1)))
	{
		free((void *)save);
		return (NULL);
	}
	if (save[i] == c)
		i++;
	while (save[i])
	{
		new_s1[j] = save[i];
		j++;
		i++;
	}
	i = gnl_if_free(new_s1, j, save);
	return (i ? new_s1 : 0);
}

char		*gnl_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	size;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_s = malloc(sizeof(char) * (size + 1))))
	{
		if (s1)
			free((void *)s1);
		free(s2);
		return (0);
	}
	i = 0;
	j = 0;
	if (s1)
		while (i < ft_strlen(s1))
			new_s[i++] = s1[j++];
	free((void *)s1);
	j = 0;
	while (i < size)
		new_s[i++] = s2[j++];
	new_s[size] = '\0';
	return (new_s);
}

size_t		ft_strlen(const char *s)
{
	char	*s1;
	size_t	i;

	if (!s)
		return (0);
	s1 = (char *)s;
	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}
