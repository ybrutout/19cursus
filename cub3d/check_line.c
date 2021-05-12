/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:12:11 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/12 15:57:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/libft.h"

int	check_R(char *str, t_struc *cub)
{
	char	*nw_str;

	nw_str = &str[2];
	cub->resol_x = ft_atoi(&nw_str);
	if (cub->resol_x < 0)
		return (-1);
	cub->resol_y = ft_atoi(&nw_str);
	if (cub->resol_y < 0)
		return (-1);
	return(1);
}

int	check_map(t_struc *cub, t_list *nw)
{
	t_list	*tmp;
	int		i;

	tmp = nw;
	while (tmp->next)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == ' ')
				i++;
			else if (tmp->line[i] == '1')
				;
		}
	}
}
