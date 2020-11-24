/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:55:16 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 11:58:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_mem;
	int		i;

    new_mem = malloc(size * count);
    i = 0;
	if (!(new_mem))
		return (0);
	while (new_mem[i])
	{
		new_mem[i] = 0;
		i++;
	}
	return (new_mem);
}