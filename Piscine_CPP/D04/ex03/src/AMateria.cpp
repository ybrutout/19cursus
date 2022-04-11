/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:07:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:20:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	//std::cout << "AMateria constructor by default called." << std::endl;
}

AMateria::AMateria(AMateria const & rhs)
{
	this->_type = rhs.getType();
	//std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	//std::cout << "AMateria constructor by string called." << std::endl;
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria deconstructor called." << std::endl;
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

void		AMateria::use(ICharacter & target)
{
	(void)target;
}
