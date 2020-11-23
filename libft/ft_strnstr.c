/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:43:14 by yannahbruto       #+#    #+#             */
/*   Updated: 2020/11/23 13:43:18 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	need = (char *)needle; 
	i = 0;
	j = 0;
	if (!(need[i]))
		return (hay);
	while(hay[i])
	{
		if (hay[i] == need[j])
		{
			if (j < len - 1)
			{
				j++; 
				i++;
			}
			else if (j == len - 1)
				return (&hay[i - j]);
		}
		else 
			i++;
			j = 0; 
	}
	return(NULL);
} 