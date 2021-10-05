/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:19:04 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/05 11:57:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ER_MALLOC 10
# define ER_ARG 11

typedef struct	s_arg
{
	int		nb_philo;
	long	tm_die;
	long	tm_eat;
	long	tm_sleep;
	int		nb_eat;
}				t_arg;

typedef struct s_philo
{
	pthread_mutex_t	*f_l;
	int				id;
	t_philo			*nxt;
	t_philo			*bef;
}				t_philo;



//LIBFT

int			ft_is_digit(char *str);
long int	ft_atoi(char *str);

//INIT

t_arg		*init_arg(void);
int			check_arg(int argc, char **argv, t_arg *arg);

//ERROR

void		clean_free(t_arg *arg, int nb, int message);

#endif
