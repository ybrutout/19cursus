/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:09:33 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 12:26:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*new_s;
	unsigned char 	new_c;
	size_t				i;

	new_s = (char *)s;
	new_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return(&new_s[i]);
		i++;
	}
	return (NULL);
}
