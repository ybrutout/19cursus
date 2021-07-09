/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:12:08 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/09 10:30:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_indx(t_col **index, int **lst_sort)
{
	int		i;
	int		j;
	t_num	*tmp;
	t_num	*col;

	j = 0;
	col = (*index)->col_a;
	while (j < (*index)->len_a)
	{
		i = 0;
		tmp = col->next;
		while (col->nb != lst_sort[0][i])
			i++;
		col->indx = i;
		j++;
		col = tmp;
	}
}

int		str_nbr(int nb)
{
	int	i;

	i = 0;
	while (nb > 1)
	{
		nb = nb / 2;
		i++;
	}
	i += 2;
	return (i);
}

char	*itoa_base_remix(int nb, int size)
{
	char	*c;

	c = malloc(sizeof(char) * size);
	if (!c)
		return(NULL);
	c[--size] = '\0';
	while (nb)
	{
		c[--size] = nb % 2 + 48;
		nb /= 2;
	}
	while (size > -1)
	{
		c[--size] = '0';
	}
	return(c);
}

void	init_binary(t_col **index, int **lst_sort)
{
	t_num	*tmp;
	t_num	*col;
	int		i;
	int		size;

	i = 0;
	col = (*index)->col_a;
	size = str_nbr((*index)->len_a - 1);
	while (i < (*index)->len_a)
	{
		tmp = col->next;
		col->binary = itoa_base_remix(col->indx, size);
		col = tmp;
		i++;
	}
}

int		there_is_a_zero(t_num *col, int nb, char c)
{
	while (col)
	{
		if (col->binary[nb] == c)
			return(0);
		col = col->next;
	}
	return (1);
}

int		this_is_a_zero(char *binary, int nb)
{
	printf("binary == %s\nnb == %d\n", binary, nb);
	if (binary[nb] == '0')
		return (0);
	return (1);
}

void	sorted_binary(t_col **index)
{
	int		i;
	int		test;
	t_num	*tmp;
	t_num	*col;
	int		f;

	i = (str_nbr((*index)->len_a) - 2);
	f = 0;
	while (i > -1)
	{
		while (there_is_a_zero((*index)->col_a, i, '0') == 0)
		{
			if (this_is_a_zero((*index)->col_a->binary, i) == 0)
			{

				push(index, 1);
			}
			else
				rotate(index, 1);
			col = (*index)->col_a;
			test = 0;
			while(test < (*index)->len_a)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
			printf("------------------------------------------------------\n");
			col = (*index)->col_b;
			test = 0;
			while(test < (*index)->len_b)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
			f++;
		}
		//if (f == 2)
		//	exit(EXIT_SUCCESS);
		/*while (there_is_a_zero((*index)->col_b, i, '1') == 0)
		{
			if (this_is_a_zero((*index)->col_b->binary, i) == 1)
				push(index, 2);
			else
				rotate(index, 2);
			col = (*index)->col_a;
			test = 0;
			while(test < (*index)->len_a)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
			printf("------------------------------------------------------\n");
			col = (*index)->col_b;
			test = 0;
			while(test < (*index)->len_b)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
			f++;
			printf("f == %d\n", f);
			//if (f == 3)
			//	exit(EXIT_SUCCESS);
		}
		if (f == 4)
			exit(EXIT_SUCCESS);*/
		while ((*index)->len_b != 0)
		{
			push(index, 2);
			col = (*index)->col_a;
			test = 0;
			while(test < (*index)->len_a)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
			printf("------------------------------------------------------\n");
			col = (*index)->col_b;
			test = 0;
			while(test < (*index)->len_b)
			{
				tmp = col->next;
				printf("%d	==	%d	=>	%d	=>	%s\n", test, col->nb, col->indx, col->binary);
				col = tmp;
				test++;
			}
		}
		i--;
	}
}

int 	big_sorted(t_col **index, int **lst_sort)
{
	*lst_sort = nw_lst_order(&(*index)->col_a, *lst_sort, (*index)->len_a, 1);
	init_indx(index, lst_sort);
	init_binary(index, lst_sort);
	sorted_binary(index);
	exit(EXIT_SUCCESS);
	return (1);
}
