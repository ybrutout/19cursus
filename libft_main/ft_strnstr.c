/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:17 by yannahbruto       #+#    #+#             */
/*   Updated: 2020/11/23 13:35:56 by yannahbruto      ###   ########.fr       */
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

int		main(void)
{
	char	haystack[] = "yannahloohan";
	char	needle[] = "yann5h";

	printf("F : %s\n", ft_strnstr(haystack, needle, 4));
	printf("V : %s\n", strnstr(haystack, needle, 4));
	return (0);
}