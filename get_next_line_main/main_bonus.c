/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:21:05 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/13 16:58:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

void	testmultiple(int fd, int fd2)
{
	char	*st;
	int		i;
	int		i2;

	st = NULL;
	i = 1;
	i2 = 1;
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	close(fd);
	close(fd2);
}

int		main()
{
	int		fd1;
	int		fd2;

	if ((fd1 = open("abc_bonus.txt", O_RDONLY)) < 0)
	{
		write(1, "je ne suis pas passé fd1 \n", 27);
		return (0);
	}
	if ((fd2 = open("123_bonus.txt", O_RDONLY)) < 0)
	{
		write(1, "je ne suis pas passé fd2 \n", 27);
		return (0);
	}
	testmultiple(fd1, fd2);
	return (0);
}


