/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:11:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/06/01 11:30:42 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_number
{
	int				nb;
	struct s_number	*next;
}					t_num;

t_num		*ft_lstnew(int *content);

typedef struct		s_column
{
	struct s_number *col_a;
	struct s_number	*col_b;
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
}					t_col;

//operation

void	swap_button(t_col **index, int button);
void	push(t_col **index, int button);
void	rotate(t_col **index, int button);
void	reverse_rot(t_col **index, int button);

//ft_libft

int		ft_atoi(const char *str);
t_num	*ft_lstnew(int *content);
t_num	*ft_lstadd_back(t_num *alst, t_num *new);
int		ft_lstsize(t_num *lst);

//parsing

int		parsing(char **argv, t_col **index);

//error

int		ft_error(t_col *index, int *lst_sort, int b);
void	free_lst(t_num *alst);

//toolbox

int		*nw_lst_order(t_num **col, int *lst_new, int len, int knob);
int		ft_order(int **lst_sort, int argc);
t_col	*int_new_index(int nb);
void	change_index(t_col **index);
void	ft_write(int button, t_col **index);

//toolbox_2

int		decreasing(t_num **col_b);
int		ascending(t_num **col_a);
int		nb_min(t_num **col_a, int nb);
int		nb_max(t_num **col_a, int nb);
int		nb_second_max(t_num **col_a, int nb, int max);

//toolbox_3

int		last_nb(t_num *col);

//sorted
int		sorted(t_col **index, int **lst_sort);

//push_swap
void	tester(t_col **index); // a enlever

#endif
