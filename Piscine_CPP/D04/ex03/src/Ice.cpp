/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:06:50 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:21:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice() : AMateria()
{
	//std::cout << "Ice constructor by default called." << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
	//std::cout << "Ice copy constructor called." << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	//std::cout << "Ice deconstructor called." << std::endl;
}

Ice			&	Ice::operator=(Ice const & rhs)
{
	(void)rhs;
	return *this;
}

AMateria	*	Ice::clone()const
{
	Ice		*nw = new	Ice;
	return (nw);
}

void			Ice::use(ICharacter & target)
{
	std::cout << "*shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
