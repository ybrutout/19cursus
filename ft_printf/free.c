/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/06 10:56:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_free(char **str)
{
	int     i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void		ft_struct(t_point *conv)
{
	(*conv).dot = 0;
	(*conv).minus = 0;
	(*conv).precision = 0;
	(*conv).width = 0;
	(*conv).zero = 0;
}
