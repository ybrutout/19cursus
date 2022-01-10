/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/10 17:02:43 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int	ft_error(int nb)
{
	if (nb == 0)
		printf("Error: Argument\n");
	else if (nb == 1)
		printf("Error: Operation file corrupted\n");
	return (1);
}

t_area	*init_area(FILE *file)
{
	t_area	*area;
	int		ret;

	area = malloc(sizeof(t_area));
	if (!area)
		return (NULL);
	if ((ret = fscanf(file, "%d %d %c\n", &(area->width), &(area->height), &(area->bgr))) != 3)
	{
		write(1, "je suis la\n", 11);
		return (NULL);
	}
	if (area->width < 1 || area->width > 300 || area->height < 1 || area->height > 300)
	{
		free(area);
		return(NULL);
	}
	if (ret < 0)
	{
		free(area);
		return (NULL);
	}
	return (area);
}

char	**paint_background(t_area *area)
{
	char	**background;
	int		i;
	int		j;

	i = -1;
	background = malloc(sizeof(char*) * ((area->height) + 1));
	if (!background)
		return(NULL);
	while (++i < area->height)
	{

		background[i] = malloc(sizeof(char) * (area->width) + 1);
		if(!background[i])
		{
			//free_cl
			return(NULL);
		}
		j = 0;
		while (j < area->width)
		{
			background[i][j] = area->bgr;
			j++;
		}
		background[i][j] = '\0';
	}
//	background[i] = NULL;
	printf("area->height == %d\narea->wight == %d\n", area->height, area->width);
	i = 0;
	j = 0;
	while (i < area->height)
	{
		printf("%s\n", background[i]);
		i++;
	}
	return(background);
}

void	draw_the_rec

t_sharpe	*init_sharpe(FILE *file, t_area *area, char **background)
{
	t_sharpe	*sharpe;

	sharpe = malloc(sizeof(t_sharpe));
	if (!sharpe)
		return (NULL);
	while (fscanf(file, "%c %f %f %f %f %c\n", &(sharpe->c), &(sharpe->x), &(sharpe->y), &(sharpe->width), &(sharpe->height), &(sharpe->chr)) == 6)
	{
		if (sharpe->width > 0.0000000 && sharpe->height > 0.000000 && (sharpe->c == 'r' || sharpe->c == 'R'))
			return (sharpe);
		draw_the_rec
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	FILE 		*file;
	t_area		*area;
	t_sharpe	*sharpe;
	int			mal;
	char		**background;
	//int			i;

	if (argc != 2)
		return (ft_error(0));
	file = fopen(argv[1], "r");
	if (!file)
		return (ft_error(1));
	area = init_area(file);
	if (!area)
		return (ft_error(1));
	mal = 1;
	background = paint_background(area);
	if (!background)
		return(ft_error(2));
	sharpe = init_sharpe(file);
	if (!sharpe)
		return(ft_error(1));
	printf("%d, %d, %c\n", area->width, area->height, area->bgr);
	printf("%c, %f, %f, %f, %f, %c\n", sharpe->c, sharpe->x, sharpe->y, sharpe->width, sharpe->height, sharpe->chr);
	fclose(file);
	return (0);
}

//	printf("area.wight == %d\narea.height == %d\narea.bgr == %c", area->width, area->height, area->bgr);
