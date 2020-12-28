/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:49:39 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/28 14:31:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char					*ft_error(int fd, char **line)
{
	char				*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if(!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	return(buffer);
}

char				*gnl_linecpy(char *line, char save)
{

}

int					get_next_line(int fd, char **line)
{
	static char		*save;
	long long int	size;
	char			*buffer;

	size = 1;
	if(!(buffer = ft_error(fd, line)))
		return(NULL);
	while (save != 0 && size != 0)
	{
		if ((size = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[size] = 0;
		if (!(save = gnl_strjoin(save, buffer)))
			return(0);
	}
	free(buffer);
	if (!(*line = gnl_linecpy))
	{

	}

}
