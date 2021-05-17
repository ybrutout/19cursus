/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:08:27 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/17 15:32:31 by ybrutout         ###   ########.fr       */
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

int			ft_atoi(const char *str);
t_num		*ft_lstnew(int *content);
void		ft_lstadd_back(t_num **alst, t_num *new);
void		ft_free(t_num *alst);
int			parsing(char **argv, t_num **col_a, t_num **col_b, int **lst_sort);
void		swap_button(t_num **col_a, t_num **col_b, int button);

#endif
