/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:06 by ybrutout          #+#    #+#             */
/*   Updated: 2021/09/29 14:04:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_the_good_option(void)
{
	;
}

void	ft_message(int message)
{
	if (message == ER_MALLOC)
	{
		write(1, "Error : Malloc\n", 15);
		exit(EXIT_FAILURE);
	}
	else if (message == ER_ARG)
	{
		write(1, "Error : Wrong Argument\n", 23);
		ft_write_the_good_option();
		exit(EXIT_SUCCESS);
	}
}

void	clean_free(t_arg *arg, int nb, int message)
{
	if (nb > 0)
	{
		free(arg);
	}
	ft_message(message);
}
