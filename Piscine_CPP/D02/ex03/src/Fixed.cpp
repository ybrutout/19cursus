/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:34 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 13:46:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(int const rb){
	//std::cout << "Int constructor called" << std::endl;
	this->_RawBits = rb << this->_comma;
	return ;
}

Fixed::Fixed(float fl){
	//std::cout << "Float constructor called" << std::endl;
	this->_RawBits = (int)roundf(fl * (1 << this->_comma));
	return ;
}

Fixed::Fixed(void) : _RawBits(0){
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & fixed){
	// std::cout << "Copy constructor called" << std::endl;
	this->_RawBits = fixed.getRawBits();
	return ;
}

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
	return ;
}

		/* ADD Overload Operateur*/
	/*Assignement Operator*/

Fixed	&	Fixed::operator=(Fixed const & fixed)
{
	this->_RawBits = fixed.getRawBits();

	return (*this);
}

	/*Comparison Operator*/

bool	Fixed::operator<(Fixed const & rhs)const
{
	if (this->_RawBits < rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator>(Fixed const & rhs)const
{
	if (this->_RawBits > rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator<=(Fixed const & rhs)const
{
	if (this->_RawBits <= rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator>=(Fixed const & rhs)const
{
	if (this->_RawBits >= rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_RawBits != rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	if (this->_RawBits == rhs.getRawBits())
		return (1);
	return (0);
}

	/*Arithmetique Operator*/

Fixed	Fixed::operator+(Fixed const & rhs)
{
	this->setRawbits(this->getRawBits() + rhs.getRawBits());
	return (*this);
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	this->setRawbits(this->getRawBits() - rhs.getRawBits());
	return (*this);
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	this->setRawbits(this->getRawBits() * rhs.getRawBits() >> this->_comma);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	this->setRawbits(this->getRawBits() / rhs.getRawBits() << this->_comma);
	return (*this);
}

	/*Increment / Decrement Operator*/

Fixed	Fixed::operator++(void)
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_RawBits--;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed f = *this;
	this->_RawBits++;
	return (f);
}

Fixed		Fixed::operator--(int)
{
	Fixed f = *this;
	this->_RawBits--;
	return (f);
}

/*member fonction min max*/

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

/*min and max member fubction with const parameters*/

Fixed const		Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const		Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}


void	Fixed::setRawbits(int const rb){
	this->_RawBits = rb;
}

int		Fixed::getRawBits( void )const{
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
