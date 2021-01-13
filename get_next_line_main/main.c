/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:20:01 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/13 15:11:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*str = NULL;
	int		i;
	int 	j;

	i = 1;
	j = 1;
	if ((fd = open("test_long_line.txt", O_RDONLY)) < 0)
	{
		write(1, "le fichier ne s'est pas ouvert\n", 31);
		return (1);
	}
	while (j < 10)
	{
		i = get_next_line(fd, &str);
		printf("%d.%d :%s\n", j, i, str);
		j++;
	}
	if ((close(fd)) < 0)
		return (1);
	return (0);
}
