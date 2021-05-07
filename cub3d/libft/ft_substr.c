/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:21:32 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		new_s = (char *)ft_calloc(sizeof(char), 1);
		if (!new_s)
			return (NULL);
		return (new_s);
	}
	if (len > ft_strlen(s) - start + 1)
		len = ft_strlen(s) - start;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	j = len;
	while (s[start] && len--)
		new_s[i++] = s[start++];
	new_s[j] = '\0';
	return (new_s);
}
