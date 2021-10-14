/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/14 10:45:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_write(int nb, t_philo *philo, t_lst_philo *lst, t_arg *arg)
{
	long int	time;

	pthread_mutex_lock(arg->write_mut);
	time = ft_actual_time(philo, lst, arg);
	ft_putnbr((time - philo->start_tm));
	write(1, " ", 1);
	ft_putnbr(philo->id);
	if (nb == FORK)
		write(1, " has taken a fork\n", 18);
	else if (nb == EAT)
	{
		write(1, " is eating\n", 11);
		philo->lst_eat = ft_sleep(arg->tm_eat, lst) - philo->start_tm;
	}
	else if (nb == SLEEP)
		write(1, " is sleeping\n", 13);
	else if (nb == THINK)
		write(1, " is thinking\n", 13);
	else if (nb == DEAD)
	{
		write (1, " died\n", 6);
		exit(EXIT_SUCCESS);
		if (nb > 5)
			clean_free(lst, philo, 0, ER_MALLOC);//changer la gestion d'erreur
	}
	pthread_mutex_unlock(arg->write_mut);
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg		*arg;
	t_lst_philo	*lst_phil;
	t_lst_philo	*tmp_lst;
	int			*beguin;
	int			i;

	arg = init_arg(argc, argv);
	printf("nb_philo == %d\ntm_die == %ld\n", arg->nb_philo, arg->tm_die); //test
	printf("tm_eat == %ld\n", arg->tm_eat); //test
	printf("tm_sleep == %ld\nnb_eat == %d\n", arg->tm_sleep, arg->nb_eat); //test
	beguin = malloc(sizeof(int));//proteger beguin
	*beguin = 1;
	lst_phil = init_lst_philo(arg, beguin);
	tmp_lst = lst_phil;
	i = 0;
	while (i < arg->nb_philo)
	{
		if (pthread_create(&tmp_lst->philo->phil_id, NULL, routine, tmp_lst) != 0)
		{
			write(1, "hey\n", 4);//a enlever
			exit(EXIT_FAILURE);//a enlever
			clean_free(lst_phil, lst_phil->philo, arg->nb_malloc, ER_PTH_C);
		}
		tmp_lst = tmp_lst->next;
		i++;
	}
	*beguin = 0;
	tmp_lst = lst_phil;
	i = 0;
	while (i < arg->nb_philo)
	{
		if (pthread_join(tmp_lst->philo->phil_id, NULL) != 0)
			clean_free(lst_phil, lst_phil->philo, arg->nb_malloc, ER_PTH_J);
		tmp_lst = tmp_lst->next;
		i++;
	}
	return (0);
}
