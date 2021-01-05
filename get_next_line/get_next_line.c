/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:49:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/05 16:26:40 by ybrutout         ###   ########.fr       */
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
	ssize_t			reader;

	if (fd < 0 || fd > OPEN_MAX || !line  || BUFFER_SIZE < 1)
		return(-1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE +1))))
		return (-1);
	reader = BUFFER_SIZE + 1;
	while (gnl_cmp(save, '\n') == 0 && reader > 0)
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) < 0)
			return(-1);
		buffer[reader] = 0;
		save = gnl_strjoin(save, buffer);
	}
	if (reader < BUFFER_SIZE)
	{
		*line = gnl_strdup(save, '\0');
		free((void*)save);
		return (0);
	}
	if (gnl_cmp(save, '\n') > 0)
	{
		*line = gnl_strdup(save, '\n');
		gnl_sve(save, '\n');
		return (1);
	}
	return (-1);
}
