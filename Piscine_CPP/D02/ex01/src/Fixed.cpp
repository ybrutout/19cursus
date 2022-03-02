/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:34 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/02 11:04:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(int const rb){
	std::cout << "Integer constructor called" << std::endl;
	this->_RawBits = rb << this->_comma;
	return ;
}

Fixed::Fixed(float fl){
	float i = 8.0000;
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = (int)roundf(fl << i)
	return ;
}

Fixed::Fixed(void) : _RawBits(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & fixed) : _RawBits(fixed.getRawBits()){
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Fixed	&	Fixed::operator=(Fixed const & fixed){
// 	std::cout << "Copy assignment called" << std::endl;

// 	if (this != &fixed)
// 		this->_RawBits = fixed.getRawBits();

// 	return (*this);
// }

int 	Fixed::getRawBits( void )const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_RawBits);
}

// void	Fixed::setRawBits( int const raw){
// 	std::cout << "setRawBits member function called with " << raw << std::endl;

// 	this->_RawBits = raw;
// 	return ;
// }

// int		Fixed::getComma(void)const{
// 	return (this->_comma);
// }

// int		FIXED::toInt(void)const{
// 	int i;

// 	i = (this->getRawBits >> this->getComma);

// 	return (i);
// }

// std::ostream & operator<<(std::ostream & o, Integer const & rhs){
// 	o << rhs.getRawBits();
// 	return o;
// }
