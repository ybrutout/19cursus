/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:12:48 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 09:27:16 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & dog) : Animal()
{
	this->type = dog.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

void		Dog::makeSound()const
{
	std::cout << "Woof woof" << std::endl;
}

Dog	&	Dog::operator=(Dog const & dog)
{
	std::cout << "Operator = called" << std::endl;
	this->type = dog.type;
	return(*this);
}
