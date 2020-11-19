/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:56:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:16 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *src;

	src = (char *)s;
	while (src)
	{
		if ( *src == (char)c)
			return (src);
		src++;
	}
	if (*src == (char)c)
		return(src);
	return (0);
}

int		main(void)
{
	char a[20] = "yannah";
	char b[20] = "loohan";
	char c[20] = "nahama";
	//int d = 0;
	int e = 110;

	printf("moi : %s\n", ft_strchr(a, e));
	printf("moi : %s\n", ft_strchr(b, e));
	printf("moi : %s\n", ft_strchr(c, e));
	printf("lui : %s\n", strchr(a, e));
	printf("lui : %s\n", strchr(b, e));
	printf("lui : %s\n", strchr(c, e));
	return (0);
}
