/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:17:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 14:45:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static float sign(Point const & p1, Point const & p2, Point const & p3)
{
	return (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y()) - (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y());
}

bool bsp(Point const & p1, Point const & p2, Point const & p3, Point const & point)
{
	float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, p1, p2);
    d2 = sign(point, p2, p3);
    d3 = sign(point, p3, p1);
	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	printf("has_neg == %B", has_neg);
    has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);
	printf("has_pos == %B", has_pos);

	printf("last == %B", !(has_neg && has_pos));

    return !(has_neg && has_pos);
}
