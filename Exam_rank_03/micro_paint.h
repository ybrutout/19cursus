/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:35:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/10 15:18:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	c;
	char	**draw;
}	t_zone;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	int		height;
	int		width;
	char	charactere;
}	t_rect;

#endif
