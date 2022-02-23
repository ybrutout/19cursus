/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:42:58 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/21 15:40:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getvalue();
	return o;
}

Integer::Integer(int const n): _n(n) {
	std::cout<<"Constructor called with value "<< n << std::endl;
	return ;
}

Integer::~Integer(void){
	std::cout<<"Déconstructor called" << std::endl;
	return ;
}

int          Integer::getvalue(void)const{
	return this->_n;
}

Integer &     Integer::operator=(Integer const & rhs){
		std::cout << "Assignation operator called from " << this->_n;
		std::cout << " to " << rhs.getvalue() << std::endl;

		this->_n = rhs.getvalue();

		return *this;
}

Integer       Integer::operator+(Integer const & rhs)const{
		std::cout <<"Addition operator called with " << this->_n;
		std::cout << " and " << rhs.getvalue() << std::endl;

		return Integer(this->_n + rhs.getvalue());
}
