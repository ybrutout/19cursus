/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:51:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 14:15:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

/*Constructor and Deconstructor*/

Point::Point(void) : x(0), y(0){
	std::cout << "Constructor by default called" << std::endl;
}

Point::~Point(void){
	std::cout << "Destructor by default called" << std::endl;
}

Point::Point(float const fl1, float const fl2) : x(fl1), y(fl2){
	std::cout << "Float const constructor called" << std::endl;
}

Point::Point(Point const &point) : x(point.get_x()) , y(point.get_y()){
	std::cout << "Copy constructor called" << std::endl;
}

/*Surcharge d'opérateur par affectation*/

Point	&	Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}

Fixed	Point::get_x(void) const{
	return (this->x);
}

Fixed	Point::get_y(void) const{
	return(this->y);
}


