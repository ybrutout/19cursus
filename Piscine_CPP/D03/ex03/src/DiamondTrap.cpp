/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:25:18 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 10:06:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap("_ClapTrap"), ScavTrap(), FragTrap()
{
	this->name = name;
	std::cout << "DiamondTrap " << this->name;
	std::cout << " is born." << std::endl;
	this->ScavTrap::energy_p = 50;
	//this->show_the_value();
}

DiamondTrap::DiamondTrap() : ClapTrap("default_CLapTrap"), ScavTrap(), FragTrap()
{
	std::cout << "The DiamondTrap is born, by default constructor." << std::endl;
	this->name = "Default";
	this->ScavTrap::energy_p = 50;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name;
	std::cout << " deconstructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & diamond) : ClapTrap(diamond), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap " << this->name;
	std::cout << " constructor by copy called." << std::endl;
}

DiamondTrap	&	DiamondTrap::operator=(DiamondTrap const & diamond)
{
	std::cout << "The DiamondTrap " << this->name;
	std::cout << " become " << diamond.name << "." << std::endl;
	this->name = diamond.name;
	this->hit_p = diamond.hit_p;
	this->energy_p = diamond.energy_p;
	this->damage = diamond.damage;
	return (*this);
}

void			DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void			DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << " and my ClapTrap name is ";
	std::cout << this->ClapTrap::name << "."<< std ::endl;
}

void			DiamondTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The DiamondTrap " << this->name << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The DiamondTrap " << this->name << " he has no energy left." << std::endl;
}
