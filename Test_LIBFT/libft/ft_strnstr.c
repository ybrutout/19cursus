/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:43:14 by yannahbruto       #+#    #+#             */
/*   Updated: 2020/11/24 12:56:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;
	size_t	len_need;

	hay = (char *)haystack;
	need = (char *)needle;
	i = 0;
	if (need[i] == 0)
		return (hay);
	len_need = ft_strlen(need);
	while (hay[i] && len_need <= len)
	{
		if (hay[i] == *need && ft_memcmp(&hay[i], need, len_need) == 0)
			return (&hay[i]);
		i++;
		len--;
	}
	return (NULL);
}
