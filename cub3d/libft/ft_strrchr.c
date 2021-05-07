/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:29:56 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = ft_strlen(src) - 1;
	if (c == 0)
		return (src + i + 1);
	while (i >= 0)
	{
		if (src[i] == (char)c)
			return (src + i);
		i--;
	}
	return (0);
}
