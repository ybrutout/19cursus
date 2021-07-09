/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 08:37:11 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/09 08:52:05 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

char	*strjoin(char *line, char c)
{
	int		 size;
	char	*nw_line;

	size = 0;
	while (line[size])
		size++;
	if (!(nw_line = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	size = 0;
	while (line[size])
	{
		nw_line[size] = line[size];
		size++;
	}
	nw_line[size] = c;
	nw_line[size + 1] = '\0';
	free(line);
	return(nw_line);
}


int		get_next_line(char **line)
{
	char	*buffer;
	int		ret;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer || !line || !(*line = malloc(sizeof(char) * 1)))
		return (-1);
	line[0][0] = '\0';
	while ((ret = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break;
		if (!(*line = strjoin(*line, buffer[0])))
			return(-1);
	}
	free(buffer);
	return(ret);
}
