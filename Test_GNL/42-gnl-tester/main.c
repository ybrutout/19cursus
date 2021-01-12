/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/13 16:12:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#include "logutil/logutil.h"
int	get_next_line(int, char**);

#define COLCOUNT 42

/*
** Prints up to COLCOUNT characters from the given string.
** @return
** 	false The string was fully printed.
** 	true  The string was partially printed.
*/
static short printline_row(const char* line, short isEOF){
	char lastChar = 0;
	(void)isEOF;
	int i;

	if (!line){
		printfc(RED, 1, "%-*.*s", COLCOUNT, COLCOUNT, NULL);
		printf("\n");
		return 0;
	}

	// Prints the characters
	for(i=0; i<COLCOUNT; i++){
		if (line[i]){
			lastChar = line[i];
			if (line[i] == '\n')
				printfc(RED, 1, "$");
			else if (isspace(line[i]))
				printf(" ");
			else
				printf("%c", line[i]);
		} else {
			printf("%-*c", COLCOUNT-i, ' ');
			break;
		}
	}

	// Prints their hex values
	for (i=0; i<COLCOUNT; i++){
		int colour;
		switch (line[i])
		{
			default:   colour=CLEAR;  break;
			case '\r': colour=YELLOW; break;
			case '\n': colour=RED;    break;
			case '\0': colour=GREEN;  break;
		}

		printfc(colour, 0, "%.*c%02X", i>0, ' ', line[i]);
		if (!line[i])
		{
			printf("%-*c", COLCOUNT-i, ' ');
			printf("\n");
			return 0;
		}
	}

	printf("\n");
	return line[i] != 0;
}

/*
** Calls GNL once on the given file.
** @return The return vlue of GNL.
*/
int TestOneGNL(int fd){
	char* line = NULL;
	int err;

	err = get_next_line(fd, &line);
	char* cursor = line;

	printf("%i|", err);
	if (-1 < err)
		while (printline_row(cursor, err == 0)){
			printf("  ");
			cursor += COLCOUNT;
		}
	else
		printfc(MAGENTA, 1, "Returned %d\n", err);

	if (line)
		free(line);

	return err;
}

int	main(int argc, char **args){
	int fd = 0;

	errno = 0;
	if (argc > 1)
		fd = open(args[1], O_RDONLY);
	if (errno == 2){
		errno = 0;
		fd = atoi(args[1]);
		if (errno == 22)
			errno = 2;
	}
	if (errno){
		printfc(YELLOW, 1, "Error opening file: errno %#d\n", errno);
		return errno;
	}

	while(0 < TestOneGNL(fd));
	TestOneGNL(fd);
}
