/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:17:23 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 13:51:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;

}

Cat::Cat(Cat const & cat) : Animal()
{
	this->type = cat.type;
	this->_brain = new Brain(*cat.getBrain());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete	this->_brain;
	std::cout << "Cat deconstructor called" << std::endl;
}

void		Cat::makeSound()const
{
	std::cout << "Meow meow" << std::endl;
}

Cat	&	Cat::operator=(Cat const & cat)
{
	std::cout << "Operator = called" << std::endl;
	this->type = cat.type;
	delete this->_brain;
	this->_brain = new	Brain(*cat._brain);
	return(*this);
}

Brain		*Cat::getBrain(void)const
{
	return this->_brain;
}

std::string	Cat::getIdea(int i)const
{
	return this->_brain->getIdea(i);
}

void		Cat::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}
