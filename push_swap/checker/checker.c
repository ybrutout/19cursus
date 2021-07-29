/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:36:02 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/29 10:54:32 by ybrutout         ###   ########.fr       */
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

int	ft_error(t_col **index, char *line, int nb)
{
	free(line);
	write(1, "Error\n", 6);
	return(-1);
}

int	ft_compare(t_col **index, char *line)
{
	if (ft_strcmp_check(line, "sa\n") == 1)
		ft_operation(index, 1);
	else if (ft_strcmp_check(line, "sb\n") == 1)
		ft_operation(index, 2);
	else if (ft_strcmp_check(line, "ss\n") == 1)
		ft_operation(index, 3);
	else if (ft_strcmp_check(line, "pb\n") == 1)
		ft_operation(index, 5);
	else if (ft_strcmp_check(line, "pa\n") == 1)
		ft_operation(index, 4);
	else if (ft_strcmp_check(line, "ra\n") == 1)
		ft_operation(index, 6);
	else if (ft_strcmp_check(line, "rb\n") == 1)
		ft_operation(index, 7);
	else if (ft_strcmp_check(line, "rr\n") == 1)
		ft_operation(index, 8);
	else if (ft_strcmp_check(line, "rra\n") == 1)
		ft_operation(index, 9);
	else if (ft_strcmp_check(line, "rrb\n") == 1)
		ft_operation(index, 10);
	else if (ft_strcmp_check(line, "rrr\n") == 1)
		ft_operation(index, 11);
	else
		return (0);
	return (1);
}

int	get_next_line_mix(t_col **index)
{
	int		ret;
	char	buffer[2];
	char	*line;
	int		i;

	line = NULL;
	buffer[1] = '\0';
	i = 0;
	while (1)
	{
		ret = read(0, buffer, 1);
		line = ft_strcat(line, buffer);
		if (ret < 0 || !line)
			return (ft_error(index, line, i));
		if (!ret)
			break ;
		if (*buffer == '\n')
		{
			if (ft_compare(index, line) == 0)
			{
				return (ft_error(index, line, i));
			}
			free(line);
			line = NULL;
		}
		i++;
	}
	free(line);
	return (1);
}

int	last_check(t_col **index)
{
	t_num 	*col_a;
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
	t_col *index;

	if (argc == 1)
		return (0);
	if (check_arg((argc - 1), argv) != 1)
		return (0);
	index = int_new_index((argc - 1), argv);
	if (!index)
		return (0);
	if (get_next_line_mix(&index) < 0)
		return (0);
	last_check(&index);
	ft_free_check(&index);
	return (1);
}
