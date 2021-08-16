/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:52:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 10:13:14 by ybrutout         ###   ########.fr       */
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
