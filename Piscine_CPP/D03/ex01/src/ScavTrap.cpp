/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:51:29 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/24 15:42:57 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->name;
	std::cout << " is born." << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "The ScavTrap is born, by default constructor." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name;
	std::cout << " deconstructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap " << this->name;
	std::cout << " constructor by copy called." << std::endl;
}

ScavTrap	&	ScavTrap::operator=(ScavTrap const & scav)
{
	std::cout << "The ScavTrap " << this->name;
	std::cout << " become " << scav.name << "." << std::endl;
	this->name = scav.name;
	this->hit_p = scav.hit_p;
	this->energy_p = scav.energy_p;
	this->damage = scav.damage;
	return (*this);
}

void			ScavTrap::guardGate(void)
{
	std::cout << "The ScavTrap " << this->name;
	std::cout << " is in mode guard gade." << std::endl;
}

void			ScavTrap::attack(const std::string& target)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "ScavTrap " << this->name << " attacks " << target;
	std:: cout << ", causing " << this->damage << " points of damage." << std::endl;
	this->energy_p--;
}

void			ScavTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The ScavTrap " << this->name << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The ScavTrap " << this->name << " he has no energy left." << std::endl;
}
