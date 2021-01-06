/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:49:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/06 16:02:59 by ybrutout         ###   ########.fr       */
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
	free((void*) buffer);
	*line = gnl_strdup(save, '\n');
	save = gnl_sve(save, '\n');
	if (reader == 0 && !save)
		return (0);
	if (*line)
		return (1);
	return (-1);
}
