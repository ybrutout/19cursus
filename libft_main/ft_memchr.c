/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:09:33 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 14:18:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char 	new_c;
	size_t				i;

	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return(&new_s[i]);
		i++;
	}
	return (NULL);
}

int		main(void)
{
	char	s[] = "yannahloohanetnahama";
	int		c;
	size_t	n;

	c = 121;
	n = 24;
	printf("F new pointeur : %p\n", ft_memchr(s, c, n));
	printf("V new pointeur : %p\n", memchr(s, c, n));
}