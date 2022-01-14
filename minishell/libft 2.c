/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:54:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/28 15:41:16 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcpy(char *dst, char *src)
{
	int	len;
	int i;

	if (!src || !dst)
		return (-1);
	len = ft_str_len(src);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	return (i);
}

int	ft_str_len(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
		;
	return (i);
}

int	tab_str_len(char **tabstr)
{
	int	i;

	i = -1;
	while (tabstr[++i])
		;
	return (i);
}
