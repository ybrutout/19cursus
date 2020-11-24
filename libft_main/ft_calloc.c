/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:55:16 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 14:57:05 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_mem;

	new_mem = malloc(size * count);
	if (!(new_mem))
		return (0);
	ft_bzero(new_mem, count * size);
	return (new_mem);
}