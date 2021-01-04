/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:12:22 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/04 14:17:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			gnl_strcmp(char *s1, char c, char **line)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != c)
	{
		line[i] = s1[i];
		i++;
	}
	line[i] = 0;
	return (0);
}

void		gnl_strcpy(char *save, char **line)
{
	size_t	i;
	while (save[i] && save[i] == '\n')
	{
		line[0][i] = save[i];
		i++;
	}
	line[0][i] = 0;
}

void		gnl_sve(char *save)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i])
		i++;
	while (save[i])
	{
		save[j] = save[i];
		i++;
		j++;
	}
	save[j] = 0;
}
