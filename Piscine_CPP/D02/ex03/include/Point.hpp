/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:41:50 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 14:16:49 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(float const fl1, float const fl2);
		Point(Point const & point);
		~Point(void);

		Point	&	operator=(Point const & rhs);

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
	private:
		Fixed const x;
		Fixed const	y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
