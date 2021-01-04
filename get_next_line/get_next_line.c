/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:49:39 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					gnl_cmp(char *str, char c)
{
	size_t			i;

	i = 0;
	if (!str || !c)
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

	if (fd < 0 || !line )
		return(-1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE +1))))
		return (-1);
	reader = 1;
	if (gnl_cmp(save, '\n') > 0)
	{
		gnl_strcpy(save, line);
		gnl_sve(save);
	}
	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
	}
}
