/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:35 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 14:50:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & AAnimal)
{
	this->type = AAnimal.type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal deconstructor called" << std::endl;
}

AAnimal	&		AAnimal::operator=(AAnimal const & AAnimal)
{
	std::cout << "Operator = called" << std::endl;
	this->type = AAnimal.type;
	return(*this);
}


