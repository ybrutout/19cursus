/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:12:54 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(char *s, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	src = s;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}
