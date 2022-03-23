/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:17:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 14:28:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	float	area;
	Fixed	tmp;

	tmp = ((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (c.get_y() - a.get_y())) + (c.get_x() * (a.get_y() - b.get_y()))) / 2;

	area = tmp.toFloat();

	return (area);
}

bool bsp(Point const p1, Point const p2, Point const p3, Point const point)
{
	float	abc = area(p1, p2, p3);
	float 	abx = area(p1, p2, point);
	float	bcx = area(p2, p3, point);
	float	cax = area(p3, p1, point);

	if (abc != (abx + bcx + cax))
	{
		//std::cout << "if I'm here, I'm out" << std::endl;
		return (false);
	}
	else if (abx == 0 || bcx == 0 || cax == 0)
	{
		//std::cout << "if I'm here, I'm on" << std::endl;
		return (false);
	}
	return (true);
}
