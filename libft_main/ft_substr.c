/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:27:25 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/24 15:21:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	new_s = malloc(sizeof(char) * len);
	if (!(new_s))
		return (0);
	ft_memcpy(new_s, s[start], len);
	return (new_s);
}
