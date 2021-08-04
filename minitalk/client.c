/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:20:26 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/04 17:01:33 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
	{
		write(1, "Error\nWrong argument\n", 21);
		exit(EXIT_FAILURE);
	}
	printf("argc == %d\n", argc);
	pid = ft_atoi(argv[1]);
	printf("PID = %d \n", pid);
	kill(pid, SIGUSR1);
	return (0);
}
