/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:16:13 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 11:30:13 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# define EAT 50
# define FORK 51
# define SLEEP 52
# define THINK 53
# define DEAD 54
# define BAD_ARG 10
# define ER_MAL 11
# define ER_MUTEX 12

typedef struct s_arg
{
	int				nb_phil;
	long int		tm_die;
	long int		tm_eat;
	long int		tm_sleep;
	int				nb_meal;
	int				*wait;
	int				died;
	pthread_mutex_t *extra;
} t_arg;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		*philo_add;
	long int		last_eat;
	long int		start;
	int				id;
} t_philo;

 //ARGUMENT
 t_arg		*init_arg(t_arg *arg, char **argv);

 //PHILOSOPHERS

 //ERROR
 void		ft_error(int message);
 void		free_clean(t_arg *arg, t_philo *philo, int nb, int message);

 //LIBFT
 long int	ft_atoi(char *str);
 int		ft_is_digit(char *str);
 void		ft_putnbr(int nb);

#endif
