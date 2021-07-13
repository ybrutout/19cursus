/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:48:46 by ybrutout          #+#    #+#             */
/*   Updated: 2021/07/13 14:15:02 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_column
{
	int				nb;
	int				indx;
	char			*binary;
	struct s_column	*next;
}					t_col;

typedef struct		s_index
{
	struct s_column *col_a;
	struct s_column	*col_b;
	int				max_a;
	int				min_a;
	int				max_b;
	int				min_b;
	int				min;
	int				max;
	int				argc;
	int				len_a;
	int				len_b;
	int				last_a;
	int				last_b;
	int				stack;
}					t_ind;

int	ft_error(t_ind **index, int **lst, int nb, int button);
int	is_a_good_files(char **argv, t_ind **index, int **lst_sort);

//ft_libft
int		ft_atoi(const char *str);
t_col	*ft_lstnew(int *content);
t_col	*ft_lstadd_back(t_col *alst, t_col *new);
int	ft_lstsize(t_col *lst);

#endif
