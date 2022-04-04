/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:36:37 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 11:43:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & wronganimal)
{
	this->type = wronganimal.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

void			WrongAnimal::makeSound()const
{
	std::cout << "Hello! I'm Bob." << std::endl;
}

WrongAnimal	&		WrongAnimal::operator=(WrongAnimal const & wronganimal)
{
	std::cout << "Operator = called" << std::endl;
	this->type = wronganimal.type;
	return(*this);
}

std::string		WrongAnimal::getType(void)const
{
	return (this->type);
}
