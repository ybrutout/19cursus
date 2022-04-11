/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:33:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:21:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure() : AMateria()
{
	//std::cout << "Cure constructor by default called." << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const & rhs) : AMateria(rhs)
{
	//std::cout << "Cure copy constructor called." << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	//std::cout << "Cure deconstructor called." << std::endl;
}

Cure			&	Cure::operator=(Cure const & rhs)
{
	(void)rhs;
	return *this;
}

AMateria	*	Cure::clone()const
{
	Cure		*nw = new	Cure;
	return (nw);
}

void			Cure::use(ICharacter & target)
{
	std::cout << "*heals " << target.getName() << "'s wounds*" << std::endl;
}
