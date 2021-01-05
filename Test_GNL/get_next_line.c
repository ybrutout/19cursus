/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:49:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/05 12:59:30 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					gnl_cmp(char *str, char c)
{
	size_t			i;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int					get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save;
	int				reader;
	int				i;

	i = 0;
	if (fd < 0 || fd > OPEN_MAX || !line  || BUFFER_SIZE < 1)
		return(-1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE +1))))
		return (-1);
	reader = 1;
	while ((i = gnl_cmp(save, '\n')) == 0 && (reader > 0 || !save))
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) < 0)
			return(-1);
		save = gnl_strjoin(save, buffer);
	}
	if (gnl_cmp(save, '\n') > 0)
	{
		*line = gnl_strdup(save, '\n');
		gnl_sve(save);
		return (1);
	}
	if (reader == 0)
	{
		*line = gnl_strdup(save, 0);
		return (0);
	}
	return (-1);
}
