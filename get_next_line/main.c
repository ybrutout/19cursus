/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:20:01 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/18 10:21:31 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;
	int		size;
	int		i;

	i = -1;
	size = 18;
	if (!(fd = open("test_hummus.txt", O_RDONLY)))
		return (-1);
	str = NULL;
	while (++i < size)
	{
		get_next_line(fd, &str);
		printf("%s\n", str);
	}
	close(fd);
	return (0);
}
