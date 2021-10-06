/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:19:04 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/06 17:06:11 by ybrutout         ###   ########.fr       */
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
# define ER_GTOD 12
# define ER_PTH_C 13
# define ER_PTH_J 14

typedef struct s_arg
{
	int		nb_philo;
	long	tm_die;
	long	tm_eat;
	long	tm_sleep;
	int		nb_eat;
	int		nb_malloc;
}				t_arg;

typedef struct s_philo
{
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_t		phil_id;
	int				tm_die;
	int				lst_eat;
	int				id;
}				t_philo;

typedef struct s_lst_philo
{
	t_philo				*philo;
	struct s_lst_philo	*next;
}				t_lst_philo;

//ARG

t_arg		*init_arg(int argc, char **argv);

//LIBFT

int			ft_is_digit(char *str);
long int	ft_atoi(char *str);
t_lst_philo	*ft_lst_add_back(t_lst_philo *first, t_lst_philo *new);

//INIT

t_lst_philo	*init_lst_philo(t_arg *arg);

//ERROR

void		clean_free(t_lst_philo *lst, t_philo *philo, int nb, int message);

//GET THE TIME

long int	actual_time(t_philo *philo, t_lst_philo *lst, t_arg *arg);

#endif
