/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:36:02 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 13:42:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_check(t_col **index)
{
	if ((*index)->col_a)
		free_lst((*index)->col_a);
	if ((*index)->col_b)
		free_lst((*index)->col_b);
	free(*index);
}

int	ft_error(t_col **index, char *line)
{
	free(line);
	write(1, "Error\n", 6);
	return (-1);
}

int	get_next_line_mix(t_col **index)
{
	int		ret;
	char	buffer[2];
	char	*line;

	line = NULL;
	buffer[1] = '\0';
	ret = 1;
	while (ret != 0)
	{
		ret = read(0, buffer, 1);
		line = ft_strcat(line, buffer);
		if (ret < 0 || !line)
			return (ft_error(index, line));
		if (!ret)
			break ;
		if (*buffer == '\n')
		{
			if (ft_compare(index, line) == 0)
				return (ft_error(index, line));
			free(line);
			line = NULL;
		}
	}
	free(line);
	return (1);
}

int	last_check(t_col **index)
{
	t_num	*col_a;
	t_num	*tmp;

	if ((*index)->len_b != 0 || (*index)->len_a != (*index)->argc)
		return (write(1, "KO\n", 3));
	col_a = (*index)->col_a;
	while (col_a)
	{
		if (col_a->next && col_a->nb > col_a->next->nb)
			return (write(1, "KO\n", 3));
		col_a = col_a->next;
	}
	return (write(1, "OK\n", 3));
}

int	main(int argc, char **argv)
{
	t_col	*index;

	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) != 1)
		return (0);
	index = int_new_index((argc - 1), argv);
	if (!index)
		return (write(1, "Error\n", 6));
	if (get_next_line_mix(&index) < 0)
	{
		free_lst(index->col_a);
		free(index);
		return (0);
	}
	last_check(&index);
	ft_free_check(&index);
	return (1);
}
