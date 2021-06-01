/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:10:31 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 11:31:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_num	*nb_tmp;// n'est utile que pour les tests.
	t_num	*nb_tmp_b; // 'est utilisé que pour les tests.
	int		tmp;// n'est utile que pour les tests.
	int		tmp_b; //tests
	int		sign;//tests
	int		*lst_sort;
	t_col	*index;

	if (argc < 3)
		return (ft_error(index, lst_sort, 1));
	index = int_new_index((argc - 1));
	if (!index)
		return(ft_error(index, lst_sort, 0));
	if (parsing(argv, &index) == 0)
		return (0);
	if (sorted(&index, &lst_sort) == 0)
		return (0);
	tester(&index);
	free_lst(index->col_a);
	free_lst(index->col_b);
	free(lst_sort);
	free(index);
	system("leaks push_swap");
}

int	checker(t_col **index)
{
	t_num	*tmp;
	int		nb;

	nb = (*index)->argc;
	//printf("nb == %d\n", nb);
	tmp = (*index)->col_a;
	while (nb != 0)
	{
		if ( tmp->next && tmp->nb > tmp->next->nb)
			return (tmp->nb);
		tmp = tmp->next;
		nb--;
	}
	return (0);
}

void	tester(t_col **index)
{
	t_num	*nb_tmp; // pour les tests.
	t_num	*nb_tmp_b;// pour les tests.
	int		i;// pour les tests.
		//checker
	i = 0;//tests
	i = checker(index);
	if (i != 0)
	{
		write(1, "KO\n", 3);
		printf("je suis le mauvais %d\n", i);
	}
	else
		write(1, "OK\n", 3);
	//fin checker
	t_num	*tmp;//tests
	t_num	*tmp_b;//tests
	int		nb_a;//tests
	int		nb_b;//tests
	int		len;

	tmp_b = (*index)->col_b;
	tmp = (*index)->col_a;
	len = (*index)->argc;
	/*printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while (len != 0)
	{
		nb_a = '\0';
		nb_b = '\0';
		if (tmp)
		{
			len --;
			nb_a = tmp->nb;
			tmp = tmp->next;
		}
		else
			nb_a = ' ';
		if (tmp_b)
		{
			len--;
			nb_b = tmp_b->nb;
			tmp_b = tmp_b->next;
		}
		else
			nb_b = ' ';
		if (!tmp_b && nb_b == ' ')
			printf("		%d		|		%c		\n", nb_a, nb_b);
		else if (!tmp && nb_a == ' ')
			printf("		%c		|		%d		\n", nb_a, nb_b);
		else
		printf("		%d		|		%d		\n", nb_a, nb_b);
	}
	printf("--------------------------------|--------------------------------\n");*/
	int it = 0;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
		++it;
	}
	printf("%d\n", it);
}

/*nb_tmp = index->col_a;
	while (nb_tmp)
	{
		printf("nb == %d\n", nb_tmp->nb);
		nb_tmp = nb_tmp->next;
	}*/

/*	nb_tmp = index->col_a;
	nb_tmp_b = index->col_b;
	printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while (nb_tmp || nb_tmp_b)
	{
		tmp = '\0';
		tmp_b = '\0';
		if (nb_tmp)
		{
			tmp = nb_tmp->nb;
			nb_tmp = nb_tmp->next;
		}
		if (nb_tmp_b)
		{
			tmp_b = nb_tmp_b->nb;
			nb_tmp_b = nb_tmp_b->next;
		}
		if (tmp != '\0' && tmp_b != '\0')
			printf("		%d		|		%d		\n", tmp, tmp_b);
		else if (tmp == '\0' && tmp_b != 0)
			printf("		%c		|		%d 		\n", ' ', tmp_b);
		else if (tmp_b == '\0')
			printf("		%d		|		%c		\n", tmp, ' ');
	}
	printf("--------------------------------|--------------------------------\n");*/

/*nb_tmp = index->col_a;
	nb_tmp_b = index->col_b;
	printf("		A		|		B		\n");
	printf("--------------------------------|--------------------------------\n");
	while ((argc - 1) != 0)
	{
		if (index->len_a > 0)
		{
			tmp =	nb_tmp->nb;
			nb_tmp = nb_tmp->next;
		}
		else
			sign = 1;
		if (index->len_b > 0)
		{
			tmp_b =	nb_tmp_b->nb;
			nb_tmp_b = nb_tmp_b->next;
		}
		else
			sign = 2;
		if (sign == 1)
			printf("		%c		|		%d		\n", ' ', tmp_b);
		else if (sign == 2)
			printf("		%d		|		%c		\n", tmp, ' ');
		else
			printf("		%d		|		%d		\n", tmp, tmp_b);
		argc--;
	}
	printf("--------------------------------|--------------------------------\n");
	exit(EXIT_SUCCESS);*/
