/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:37:43 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 11:43:19 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & wronganimal) : WrongAnimal()
{
	this->type = wronganimal.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

void		WrongCat::makeSound()const
{
	std::cout << "Meuh meuh" << std::endl;
}

WrongCat	&	WrongCat::operator=(WrongCat const & wrongcat)
{
	std::cout << "Operator = called" << std::endl;
	this->type = wrongcat.type;
	return(*this);
}
