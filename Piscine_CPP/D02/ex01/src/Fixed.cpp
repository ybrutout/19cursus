/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:34 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/02 13:46:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(int const rb){
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = rb << this->_comma;
	return ;
}

Fixed::Fixed(float fl){
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = (int)roundf(fl * (1 << this->_comma));
	return ;
}

Fixed::Fixed(void) : _RawBits(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & fixed){
	std::cout << "Copy constructor called" << std::endl;
	this->_RawBits = fixed.getRawBits();
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&	Fixed::operator=(Fixed const & fixed){
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &fixed)
		this->_RawBits = fixed.getRawBits();

	return (*this);
}

int 	Fixed::getRawBits( void )const{
	return (this->_RawBits);
}

int		Fixed::getComma(void)const{
	return (this->_comma);
}

int		Fixed::toInt(void)const{
	int i;

	i = (this->_RawBits >> this->_comma);

	return (i);
}

float		Fixed::toFloat(void)const{
	float	i;

	i = (float)this->_RawBits / (1 << this->_comma);
	return (i);
}

 std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
 	o << rhs.toFloat();
 	return o;
}
