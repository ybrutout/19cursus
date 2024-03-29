/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:03:16 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/21 14:16:31 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define EAT 50
# define FORK 51
# define SLEEP 52
# define THINK 53
# define DEAD 54
# define END 55
# define ER_ARG 10
# define ER_MAL 11
# define ER_MUTEX 12
# define THR 13

# define TEST 100

typedef struct s_arg
{
	int				phill;
	long			tm_die;
	long			tm_eat;
	long			tm_sleep;
	long			start;
	int				nb_meal;
	int				end_meal;
	int				died;
	pthread_mutex_t	*sec_died;
}	t_arg;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		philo_add;
	t_arg			*arg;
	long			last_eat;
	int				id;
	int				meal;
}	t_philo;

typedef struct s_lst
{
	t_philo			*philo;
	struct s_lst	*next;
}	t_lst;

//ARGUMENT
int			init_arg(char **argv, t_arg **fst);

//ERROR
int			ft_error(int message);
int			free_clean(t_philo *philo, t_lst *lst, int nb, int message);

//LIBFT
long		ft_atoi(char *str);
int			ft_is_digit(char *str);
void		ft_putnbr(int nb);
t_lst		*ft_lst_add_back(t_lst *first, t_lst *new);

//PHILO_LST
int			init_lst(t_arg *arg, t_lst **lst);

//ROUTINE
void		*routine(void *lst);

//UTILS
long		get_current(void);
void		ft_sleep(long ms, t_arg *arg);
void		*routine_time(void *lst);
void		ft_write(int message, t_philo *philo);

#endif
