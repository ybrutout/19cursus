/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:25:18 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 13:24:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamonTrap.hpp"

DiamonTrap::DiamonTrap(std::string name) : ClapTrap(name + "_ClapTrap"), ScavTrap(), FragTrap()
{
	this->name = name;
	std::cout << "DiamonTrap " << this->name;
	std::cout << " is born." << std::endl;
	this->ScavTrap::energy_p = 50;
	//this->show_the_value();
}

DiamonTrap::DiamonTrap() : ClapTrap("default_CLapTrap"), ScavTrap(), FragTrap()
{
	std::cout << "The DiamonTrap is born, by default constructor." << std::endl;
	this->name = "Default";
	this->ScavTrap::energy_p = 50;
}

DiamonTrap::~DiamonTrap(void)
{
	std::cout << "DiamonTrap " << this->name;
	std::cout << " deconstructor called." << std::endl;
}

DiamonTrap::DiamonTrap(DiamonTrap const & diamon) : ClapTrap(diamon), ScavTrap(), FragTrap()
{
	std::cout << "DiamonTrap " << this->name;
	std::cout << " constructor by copy called." << std::endl;
}

DiamonTrap	&	DiamonTrap::operator=(DiamonTrap const & diamon)
{
	std::cout << "The DiamonTrap " << this->name;
	std::cout << " become " << diamon.name << "." << std::endl;
	this->name = diamon.name;
	this->hit_p = diamon.hit_p;
	this->energy_p = diamon.energy_p;
	this->damage = diamon.damage;
	return (*this);
}

void			DiamonTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void			DiamonTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << " and my ClapTrap name is ";
	std::cout << this->ClapTrap::name << "."<< std ::endl;
}

void			DiamonTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The DiamonTrap " << this->name << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The DiamonTrap " << this->name << " he has no energy left." << std::endl;
}
