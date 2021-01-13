/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_marge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:40:49 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/07 16:09:18 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int			main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;

	j = 1;
	int fd2;

	if (!(fd = open("half_marge_top", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	if (!(fd2 = open("half_marge_bottom", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	free(line);
	while ((i = get_next_line(fd2, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 25)
		printf("\nRight number of lines\n");
	else if (j != 25)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
}
