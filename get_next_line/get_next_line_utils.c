/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:12:22 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/28 13:55:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	size;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
		new_s[i++] = s1[j++];
	j = 0;
	while (i < size)
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (new_s);
}

