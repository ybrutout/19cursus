/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:24:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 13:04:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*new_b;
	size_t	i;

	i = 0;
	new_b = (char *)b;
	while (i < len)
	{
		new_b[i] = c;
		i++;
	}
	return (b);
}
