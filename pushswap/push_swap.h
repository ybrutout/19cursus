/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:08:27 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/26 16:26:15 by ybrutout         ###   ########.fr       */
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

void		ft_lstadd_back(t_num **alst, t_num *new);
void		ft_free(t_num *alst);
void		swap_button(t_col **index, int button);
void		push(t_col **index, int button);
void		rotate(t_col **index, int button);
void		reverse_rot(t_col **index, int button);
void		ft_write(int button, t_col **index);

int			ft_lstsize(t_num *lst);
int			parsing(char **argv, t_num **col_a, t_num **col_b, int **lst_sort);
int			ft_atoi(const char *str);
int			median(t_col **index, int **lst_sort, int nb);
int			ft_error(t_num *col_a, t_num *col_b, int *lst_sort, int b);
int			nb_min(t_num **col_a, int nb);
int			nb_max(t_num **col_a, int nb);
int			decreasing(t_num **col_b);
int			ascending(t_num **col_a);
int			ft_order(int **lst_sort, int argc);
int			*nw_lst_order(t_num **col, int *lst_new, int len);
int			nb_second_max(t_num **col_a, int nb, int max);
int			last_nb(t_num *col);

void		tester(t_col **index);

t_col		*int_new_index(t_num **col_a, t_num **col_b, int nb);

#endif
