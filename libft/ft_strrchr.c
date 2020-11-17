/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:29:56 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/17 17:28:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		ft_strlen(char *str)
{
	long unsigned int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char    *ft_strrchr(const char *s, int c)
{
    char *src;
    int i;

	src = (char *)s;
    i = ft_strlen(src) - 1;
	while (src[i])
	{
		if ( src[i] == (char)c)
			return (&src[i]);
		i--;
	}
	if (*src == (char)c)
		return(src);
	return ("\0");
}

int		main(void)
{
	char a[20] = "yannah";
	char b[20] = "loohan";
	char c[20] = "nahama";
	int d = 0;
	int e = 110;

	printf("moi : %s\n", ft_strrchr(a, e));
	printf("moi : %s\n", ft_strrchr(b, e));
	printf("moi : %s\n", ft_strrchr(c, d));
	printf("lui : %s\n", strrchr(a, e));
	printf("lui : %s\n", strrchr(b, e));
	printf("lui : %s\n", strrchr(c, d));
	return (0);
}
