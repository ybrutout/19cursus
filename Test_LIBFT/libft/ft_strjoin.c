/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:17:40 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/14 12:43:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	size;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (size + 1));
	if (!(new_s))
		return (0);
	i = 0;
	j = -1;
	while (i < ft_strlen(s1))
		new_s[i++] = s1[++j];
	j = -1;
	while (i < size)
		new_s[i++] = s2[++j];
	new_s[i] = '\0';
	return (new_s);
}
