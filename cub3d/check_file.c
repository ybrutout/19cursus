/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:50:29 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:55:55 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/get_next_line.h"
#include "includes/libft.h"

/*int	check_map(char ** str)
{

}*/

/*int	check_element(char **str)
{

}*/

/*int	check_line(char *str)
{
	int 	i;

	i = 0;
	if (str[i] == 'R')
	{
		while (str[++i])
		{
			if(ft_isdigit(str[i]));
		}

	}
}*/

int	check_dot_cub(char **argv)
{
	int		fd;
	char	**str;
	int		i;
	t_list	**dot_cub;
	t_list	*new;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "error with open\n", 16));
	while (i == 1)
	{
		i = get_next_line(fd, str);
		if (i < 0)
			return(write(1, "error gnl\n",10)); //voir si il n'y a pas un probleme d'un element non free
		new = ft_lstnew(str[0]);
		if (!new)
			return(write(1, "error malloc dans ft_lstnew\n", 28));
		ft_lstadd_back(dot_cub, new);
	}
	while (new->next)
	{
		new = new->next;
	}
	free(str[0]);
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1 || argc > 3)
		return(0);
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			if (argv[1][i + 1] == 'c')
				if (argv[1][i + 2] == 'u')
					if (argv[1][i + 3] == 'b')
						if (argv[1][i + 4] == '\0')
							return(1);
		i++;
	}
	return (write(1, "wrong files\n", 12));
}

int	ft_parsing(int argc, char **argv)
{
	if (check_arg(argc, argv) == 1)
		if (check_dot_cub(argv) == 1)
			return(1);
	return(0);
}
