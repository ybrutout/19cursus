/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:33 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/07 16:14:43 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_write(int nb, t_philo *philo)
{
	return (1);
}

void	*routine(void *lst)
{
	t_arg		*arg;
	t_lst_philo	*lst_philo;
	t_philo		*philo;
	int			i;//test
	int			j; //test

	arg = init_arg(0, NULL);
	lst_philo = (t_lst_philo*)lst;
	philo = lst_philo->philo;
	//printf("id == %d\n", philo->id);//test
	i = 1;
	j = 0;
	/*while (i)
	{*/
		if (ft_write(j++, philo) == 0)
			return (0);
		/*i++;
	}*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg		*arg;
	t_lst_philo	*lst_phil;
	t_lst_philo	*tmp_lst;
	long int	now;//test
	int			i;

	arg = init_arg(argc, argv);
	printf("nb_philo == %d\ntm_die == %ld\n", arg->nb_philo, arg->tm_die); //test
	printf("tm_eat == %ld\n", arg->tm_eat); //test
	printf("tm_sleep == %ld\n nb_eat == %d\n", arg->tm_sleep, arg->nb_eat); //test
	lst_phil = init_lst_philo(arg);
	now = actual_time(lst_phil->philo, lst_phil, arg); //test
	printf("time == %ld\n", now); //test
	i = 0;
	tmp_lst = lst_phil;
	while (i < arg->nb_philo)
	{
		tmp_lst->philo->start_tm = actual_time;
		if (pthread_create(&tmp_lst->philo->phil_id, NULL, routine, tmp_lst) != 0)
			clean_free(lst_phil, lst_phil->philo, arg->nb_malloc, ER_PTH_C);
		tmp_lst = tmp_lst->next;
		i++;
	}
	i = 0;
	tmp_lst = lst_phil;
	while (i < arg->nb_philo)
	{
		if (pthread_join(tmp_lst->philo->phil_id, NULL) != 0)
			clean_free(lst_phil, lst_phil->philo, arg->nb_malloc, ER_PTH_J);
		tmp_lst = tmp_lst->next;
		i++;
	}
	return (0);
}
