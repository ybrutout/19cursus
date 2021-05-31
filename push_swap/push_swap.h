/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:40:28 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/31 16:40:47 by ybrutout         ###   ########.fr       */
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

#endif
