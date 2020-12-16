/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:21:32 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/16 16:34:53 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_s;
	int			i;
	size_t		j;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(new_s = (char *)ft_calloc(sizeof(char), 1)))
			return (NULL);
		return (new_s);
	}
	if (len > ft_strlen(s) - start + 1)
		len = ft_strlen(s) - start;
	if (!(new_s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = len;
	while (s[start] && len)
	{
		new_s[i++] = s[start++];
		len--;
	}
	new_s[j] = '\0';
	return (new_s);
}
