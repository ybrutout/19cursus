/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:26:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 13:40:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_p = 100;
	this->energy_p = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name;
	std::cout << " is born." << std::endl;
	//this->show_the_value();
}

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_p = 100;
	this->energy_p = 100;
	this->damage = 30;
	std::cout << "The FragTrap is born, by default constructor." << std::endl;
	//this->show_the_value();
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name;
	std::cout << " deconstructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const & scav) : ClapTrap(scav)
{
	std::cout << "FragTrap " << this->name;
	std::cout << " constructor by copy called." << std::endl;
}

FragTrap	&	FragTrap::operator=(FragTrap const & scav)
{
	std::cout << "The FragTrap " << this->name;
	std::cout << " become " << scav.name << "." << std::endl;
	this->name = scav.name;
	this->hit_p = scav.hit_p;
	this->energy_p = scav.energy_p;
	this->damage = scav.damage;
	return (*this);
}

void			FragTrap::highFivesGuys(void)
{
	std::cout << "The FragTrap " << this->name;
	std::cout << " make a High Fives." << std::endl;
}

void			FragTrap::attack(const std::string& target)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "FragTrap " << this->name << " attacks " << target;
	std:: cout << ", causing " << this->damage << " points of damage." << std::endl;
	this->energy_p--;
}

void			FragTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The FragTrap " << this->name << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The FragTrap " << this->name << " he has no energy left." << std::endl;
}
