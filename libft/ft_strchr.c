/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:56:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 12:53:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = '\0';
	while (src[i])
	{
		if (src[i] == (char)c)
			return (&src[i]);
		i++;
	}
	if (src[i] == (unsigned char)c)
		return (&src[i]);
	return (0);
}
