/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:52:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/12 16:34:33 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_gen	*the_struct_b(t_gen *general)
{
	general->const_bit -= 1;
	general->nb = general->nb / 2;
	if (general->const_bit == -1)
	{
		general->const_bit = 7;
		general->i += 1;
		if (general->i < general->strlen)
			general->nb = (general->str[general->i]);
		else
		{
			free(general);
			write(1, "I received the message \n", 24);
			return (NULL);
		}
	}
	return (general);
}

t_gen	*the_struct(int pid_server, int strlen, char *arg, int button)
{
	static t_gen	*general;

	if (button == INIT)
	{
		general = malloc(sizeof(t_gen) * 1);
		if (!general)
			return (NULL);
		general->const_bit = 7;
		general->i = 0;
		general->str = arg;
		general->nb = (unsigned int)general->str[0];
		general->pid_server = pid_server;
		general->strlen = strlen;
	}
	else if (button == CHANGE)
		general = the_struct_b(general);
	return (general);
}
