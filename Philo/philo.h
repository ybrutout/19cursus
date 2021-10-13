/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:19:04 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/13 16:08:37 by ybrutout         ###   ########.fr       */
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
# define FORK 21
# define SLEEP 22
# define EAT 23
# define DEAD 24
# define THINK 25

typedef struct s_arg
{
	int				nb_philo;
	long			tm_die;
	long			tm_eat;
	long			tm_sleep;
	int				nb_eat;
	int				nb_malloc;
	int				dead;
	pthread_mutex_t	*write_mut;
}				t_arg;

typedef struct s_philo
{
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_t		phil_id;
	long int		lst_eat;
	long int		start_tm;
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
void		ft_putnbr(int nb);

//INIT

t_lst_philo	*init_lst_philo(t_arg *arg);

//ERROR

void		clean_free(t_lst_philo *lst, t_philo *philo, int nb, int message);

//GET THE TIME

long int	ft_actual_time(t_philo *philo, t_lst_philo *lst, t_arg *arg);
int			ft_sleep(long int ms, t_lst_philo *lst);

//ROUTINE

void		*routine(void *lst);

//PHILO

int			ft_write(int nb, t_philo *philo, t_lst_philo *lst, t_arg *arg);

#endif
