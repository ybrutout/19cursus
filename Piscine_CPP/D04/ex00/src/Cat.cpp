/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:17:23 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 09:27:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const & cat) : Animal()
{
	this->type = cat.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
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
	return(*this);
}
