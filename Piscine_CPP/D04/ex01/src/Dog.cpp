/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:12:48 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 13:51:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & dog) : Animal()
{
	this->type = dog.type;
	this->_brain = new Brain(*dog.getBrain());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	this->_brain;
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
	delete this->_brain;
	this->_brain = new	Brain(*dog._brain);
	return(*this);
}

Brain		*Dog::getBrain(void)const
{
	return this->_brain;
}

std::string	Dog::getIdea(int i)const
{
	return this->_brain->getIdea(i);
}

void		Dog::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}
