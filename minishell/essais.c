/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:05:20 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/27 14:25:46 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <signal.h>
#include <dirent.h>

int main(void)
{
	char	*line;
	int		i;

	while (1)
	{
		line = readline(">");
		if (line)
			printf("%s\n", line);
		if (line && *line)
		{
   			i = add_history (line);
			printf("%d\n", i);
		}
		free(line);
	}
	return (0);
}
