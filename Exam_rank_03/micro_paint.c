/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:35:11 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/10 16:06:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "micro_paint.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(i);
	while (str[i])
		i++;
	return (i);
}

int	fail_return(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	the_zone(FILE *file, t_zone *zone)
{
	int	i;
	int	j;
	if ((fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->c)) != 3)
		return (0);
	if (zone->width < 1 || zone->width > 300 || zone->height < 1 || zone->height > 300)
		return(0);
	zone->draw = malloc(sizeof (char *) * (zone->height + 1));
	if (!(zone->draw))
		return (0);
	zone->draw[zone->height] = NULL;
	i = -1;
	while (++i < zone->height)
	{

		zone->draw[i] = malloc(sizeof(char) * (zone->width + 1));
		if (!(zone->draw[i]))
			return(0);
		zone->draw[i][zone->width] = '\0';
		j = -1;
		while (++j < zone->width)
			zone->draw[i][j] = zone->c;
	}

	i = 0;
	printf("width == %d\nheight == %d\nc == %c\n", zone->width, zone->height, zone->c);
	while (zone->draw[i])
	{
		printf("%s\n", zone->draw[i]);
		i++;
	}
	return(1);
}

int	get_the_rect(FILE *file, t_zone *zone)
{
	t_rect *rect;
	int	i;
	int	j;

	while ((fscanf(file, "%c %f %f %f %f %c", &rect->type, &rect->x, &rect->y, &rect->width, &rect->height, &rect->c)) == 6)
	{
		if (rect->type != 'r' && rect->type != 'R')
			return(0);
		if (if rect->width < 1 || rect->height < 1)
			return(0);
		i = 0;
		while (zone->draw[i])
		{
			j = 0
			while (zone->draw[i][j])
			{
				if (rect->type == 'r')
					if ((j >= rect->x || j <= (rect-> x + rect->width)) && (i == rect->y || i == (rect->height) ))
						zone->draw[i][j] = rect->charactere;
				else if (rect->type == 'R')
					if ((j >= rect->x || j <= (rect-> x + rect->width)) && (i == rect->y || i == (rect->height) ))
				else
				 return(0);
				j++;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	FILE 	*file;
	t_zone	zone;

	if (argc != 2)
		return (fail_return("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (fail_return("Error: Operation file corrupted"));
	if (!(the_zone(file, &zone)))
	{
		fclose(file);
		return(0);
	}
	if (!(get_the_rect(file, &zone)))
	{
		fclose(file);
		return(0);
	}
	return (0);
}
