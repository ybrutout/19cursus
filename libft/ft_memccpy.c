/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:05:29 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/18 17:04:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src,int c, size_t n)
{
	char	*new_dst;
	char	*new_src;
	size_t	i;

	new_dst = (char *) dst;
	new_src = (char *) src;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
        if (new_src[i] == c)
        {
            i++;
            return (&dst[i]);
        }
		i++;
	}
	return (0);
}

int     main(void)
{
    char    dst[20] = "hello you";
    char    dst1[20] = "hello you";
    char    src[20] = "yannah";
    int     c;
    size_t  n;

    c = 'b';
    n = 6;
    printf("F avant : %s\n", dst);
    printf("V avant : %s\n", dst1);
    printf("F retour : %s\n",ft_memccpy (dst, src, c, n));
    printf("V retour : %s\n",memccpy(dst1, src, c, n));
    printf("F apres : %s\n", dst);
    printf("V apres ; %s\n", dst1);
    return (0);
}