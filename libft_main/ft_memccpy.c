/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:05:29 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 13:10:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
        if ((unsigned char) new_src[i] == (unsigned char) c)
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

    c = 'v';
    n = 8;
    printf("F avant : %s\n", dst);
    printf("V avant : %s\n", dst1);
    printf("F retour : %s\n",ft_memccpy (dst, src, c, n));
    printf("V retour : %s\n",memccpy(dst1, src, c, n));
    printf("F apres : %s\n", dst);
    printf("V apres ; %s\n", dst1);
    return (0);
}