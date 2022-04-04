/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:35 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 09:29:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const & animal)
{
	this->type = animal.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

void			Animal::makeSound()const
{
	std::cout << "*...Sound undefined...*" << std::endl;
}

Animal	&		Animal::operator=(Animal const & animal)
{
	std::cout << "Operator = called" << std::endl;
	this->type = animal.type;
	return(*this);
}

std::string		Animal::getType(void)const
{
	return (this->type);
}

