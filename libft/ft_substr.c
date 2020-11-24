/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:21:32 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 16:31:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (!(s))
		return (0);
	new_s = malloc(sizeof(char) * (len + 1));
	if (!(new_s))
		return (0);
	if (start >= ft_strlen(s))
		return (new_s);
	ft_memcpy(new_s, &s[start], len);
	new_s[len] = '\0';
	return (new_s);
}
