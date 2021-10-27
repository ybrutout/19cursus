/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:54:23 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/27 17:06:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
