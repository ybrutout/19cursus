/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:44:49 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/16 16:33:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ifsep(char const s1, char const *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char*)s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_ifsep(s1[i], set) && s1[i])
		i++;
	while (j > i && ft_ifsep(s1[j], set))
		j--;
	if (!(new_s = ft_substr(s1, i, (j - i + 1))))
		return (NULL);
	return (new_s);
}
