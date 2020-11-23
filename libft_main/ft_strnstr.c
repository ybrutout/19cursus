/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:17 by yannahbruto       #+#    #+#             */
/*   Updated: 2020/11/23 17:42:05 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;
    size_t  len_need;

	hay = (char *)haystack;
	need = (char *)needle; 
	i = 0;
	if (need[i] == 0)
		return (hay);
    len_need = ft_strlen(need);
    while (hay[i] && len_need <= len)
    {
        if(hay[i] == *need && ft_memcmp(&hay[i], need, len_need) == 0)
            return(&hay[i]);
        i++;
        len--;
    }
	return(NULL);
} 

int		main(void)
{
	char	haystack[] = "yannahloohan";
	char	needle[] = "yann5h";

	printf("F : %p\n", haystack);
	printf("F : %p\n", ft_strnstr(haystack, needle, 3));
	printf("V : %p\n", strnstr(haystack, needle, 3));
	return (0);
}