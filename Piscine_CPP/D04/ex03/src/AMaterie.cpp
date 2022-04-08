/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMaterie.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:07:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/08 15:33:40 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "Constructor by default called." << std::endl;
}

AMateria::AMateria(AMateria const & rhs)
{
	this->_type = rhs.getType();
	std::cout << "Copy constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << "Constructor by string called." << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "Deconstructor called." << std::endl;
}

AMateria	&			AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs.getType();
	return *this;
}

std::string	const	&	AMateria::getType()const
{
	return this->_type;
}


