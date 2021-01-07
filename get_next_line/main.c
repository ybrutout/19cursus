/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:20:01 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/07 12:49:38 by ybrutout         ###   ########.fr       */
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
	if ((fd = open("tests_hummus.txt", O_RDONLY)) < 0)
		return (1);
	while (j < 20)
	{
		i = get_next_line(fd, &str);
		printf("%d.%d :%s---\n", j, i, str);
		j++;
	}
	if ((close(fd)) < 0)
		return (1);
	return (0);
}
