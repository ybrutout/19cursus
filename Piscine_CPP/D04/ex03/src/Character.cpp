/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:57:15 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:54:16 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Character.hpp"

Character::Character() : _name("no_name")
{
	//std::cout << "Character constructor by default called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	//std::cout << "Character constructor by string called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & rhs)
{
	//std::cout << "Character copy constructor called." << std::endl;
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	//std::cout << "Character deconstructor called." << std::endl;
	for (int i = 0; i < 4 ; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character	&		Character::operator=(Character const & rhs)
{
	this->_name = rhs.getName();
	for(int i = 0; i < 4 ; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

void				Character::equip(AMateria* m)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			break;
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void				Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target)
{
	if (!this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

std::string	const &	Character::getName()const
{
	return (this->_name);
}
