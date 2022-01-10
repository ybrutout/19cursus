/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:33:57 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/10 13:57:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_area
{
	int		width;
	int		height;
	char	bgr;
}				t_area;

typedef	struct	s_sharpe
{
	char	c;
	float	x;
	float	y;
	float	width;
	float	height;
	char	chr;
}				t_sharpe;

#endif
